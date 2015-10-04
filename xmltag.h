#ifndef _XMLTAG_H
#define _XMLTAG_H
/*
xmltag.h

Class declaration for XMLTag, a simple multi-platform xml parser
that wraps the use and creation of XML into a single object.
The internal parser is a single pass XML parser that is not only
very fast but allows for midstream parsing of XML data.  The class
was designed to make using XML as a communication protocol very simple
removing the complexity from the handling of the XML that carries
the real data being communicated.


Copyright (C) 1999  Stephen D. Mathews Jr.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <string.h> // for strcmp


#define XML_BUFFER_BLOCK_SIZE   4096

/**
* If an XML rule is broken during parsing and XMLTag instance will throw an XMLTagException.
* An XMLTagException contains two members that help indentify the cause of the parser failure.
*/
struct XMLTagException
{
    /**
    * Contains a text description of the parser failure.
    */
    std::string msg;
    /**
    * Contains a sample of the cause of failure when possible.
    */
    std::string sample;
};


class XMLTag
{

private:
    std::string m_TagName;
    std::string m_Value;
    std::vector<XMLTag*>    m_vecXMLTags;
    std::map< std::string, std::string > m_mapAttributes;
    bool m_ignoreCase;
    bool m_StrictMode;
    bool m_bIncomplete;
    int m_usecTimeout;

    // Used to reference backwards and to varify
    // that the xml is formatted properly
    XMLTag* m_pParent;


    // if this has a value other than zero
    // it will be used by the parse() method
    FILE* m_fp;


    // Holds the buffer that is being parsed.
    // Also lets us stop and continue mid-stream
    std::vector<char>   m_szXMLBuffer;
    //char *    m_szXMLBuffer;
    //int       m_iXMLBufferSize;

    mutable char *  m_tempbuf;

    // This is to hold the info for the buffer that
    // is passed in for parsing.
    const char *m_pUserBufferPointer;   // Buffer passed in for parsing
    int     m_iUserBufferSize;      // Size of buffer passed in
    // m_iXMLBufferSize(above) is used to keep from going past size


    // something to return that won't crash the user app
    XMLTag*     m_pBogus;
    std::string m_junk;


    void init();

    /**
    * Internal parser for basic XML
    *
    * @return bool - true if successful
    */
    bool parse();

    /**
    * Used internally to abstract the source of the byte being retrieved for parsing.
    *
    * @param pByte  Pointer to a char to store the byte retrieved from the abstracted device.
    * @return bool - indecating success if true or failure if false.
    */
    bool getNextByte(char * pByte);

    /**
    * Used internally for determining the number of bytes the generated XML will be (formatted or not)
    *
    * @param tabs - Used to track tree depth (or not when -1)
    * @return int - byte count.
    */
    int generationByteCount(int tabs = -1) const;

    /**
    * Used internally for generated XML will be (formatted or not)
    *
    * @param tabs - Used to track tree depth (or not when -1)
    * @return int - byte count.
    */
    int generateXML(char** genbuf, int pos = 0, int tabs = -1) const;

public:

    /**
    * Default constructor
    */
    XMLTag();


    /**
    * Copy Constructor
    *
    */
    XMLTag(const XMLTag& tag);

    /**
    * Constructor
    *
    * @param pParent Mainly for internal use; pointer to parent tag containing this tag
    */
    XMLTag(XMLTag* pParent);

    /**
    * Constructor
    *
    * @param szTagName Name of a contructed tag
    * @param szValue Value of a constructed tag
    */
    XMLTag(const char* szTagName, const char* szValue);

    /**
    * Constructor
    *
    * @param szTagName Name of a contructed tag
    * @param bValue Value of a constructed tag
    */
    XMLTag(const char* szTagName, bool bValue);

    /**
    * Constructor
    *
    * @param szTagName Name of a contructed tag
    * @param intValue Value of a constructed tag
    */
    XMLTag(const char* szTagName, int intValue);

    /**
    * Constructor
    *
    * @param szTagName Name of a contructed tag
    * @param uintValue Value of a constructed tag
    */
    XMLTag(const char* szTagName, unsigned  int uintValue);

    /**
    * Constructor
    *
    * @param szTagName Name of a contructed tag
    * @param uintValue Value of a constructed tag
    */
    XMLTag(const char* szTagName, float floatValue);

    /**
    * Constructor
    *
    * @param szTagName Name of a contructed tag
    * @param uintValue Value of a constructed tag
    */
    XMLTag(const char* szTagName, double doubleValue);

    /**
    * Constructor
    *
    * @param szTagName Name of a constructed tag
    */
    XMLTag(const char* szTagName);

    /**
    * Constructor
    *
    * @param strTagName std::string input for tag name
    * @param strValue std::string input for tag value
    */
    XMLTag(std::string strTagName, std::string strValue = "");

    /**
    * Destructor
    */
    ~XMLTag();

    /**
    * Clears the name, value, all attributes, and all children of this tag
    */
    void clear();

    /**
    * By default access to tags or attibutes that do not exist return blank to prevent memory access violations.
    * When bMode is set to true, an exception is thrown containing details about the access violation.
    *
    * @param bMode bool - true activates strict mode
    */
    void strictMode(bool bMode);

    /**
    * When set to true this method tells the parser to force all tag names and attribute name to lowercase.
    * All access function that except names force all passed in name to lowercase to insure case insensitive access.
    *
    * @param bIgnore bool - true activates case insensitivity
    */
    void ignoreCase(bool bIgnore = false);

    /**
    * Loads an XML file to be parsed.
    *
    * @param szFileName const char pointer to a filename
    * @return bool - returns false if the file could not be found or loaded.
    */
    bool load(const char * szFileName);

    /**
    * This method will writes out the structure of tag objects in XML to a file.
    * If the file exists it is overwritten.
    *
    * @param szFileName const char pointer to a file name
    * @return bool - true if successful
    */
    bool store(const char * szFileName, bool bFormatted = false);

    /**
    * reads XML for parsing from a buffer pointer
    *
    * @param pBuffer const char pointer to buffer to parse.
    * @param iBufferSize
    *                size in in chars of buffer to parse
    * @return bool - true of successful
    */
    int read(const char * pBuffer, int iBufferSize = 0);

    /**
    * reads XML for parsing from the current position of an open file pointer
    *
    * @param fp     FILE pointer
    * @return bool - true of successful
    */
    bool read(FILE* fp);

    /**
    * Writes XML dynamically generated by this instance to an open file descriptor and leaves it open
    *
    * @param fp     FILE pointer
    * @return int - number of bytes written
    */
    int write(FILE* fp) const;

    /**
    * Writes XML dynamically generated by this instance to a dynamically allocated buffer.
    *
    * NOTE: The buffer must be deallocated by the user with "delete[] pYourBufferPointer;"
    *
    * @param char **pBuffer - A pointer to the buffer pointer to allocate and write to
    * @return int - number of bytes written to the buffer minus the null terminator
    */
    int write(char** pBuffer) const;

    /**
    * Returns a pointer to a NULL terminated string containing XML
    * dynamically generated by this instance.  The class manages
    *
    *
    * @return const char* - returns a pointer to an interal dynamically generated buffer of XML that represents what this object contains
    */
    const char * getXML() const;

    /**
    * Returns a pointer to a NULL terminated string containing formatted XML
    * dynamically generated by this instance.  The class manages
    *
    *
    * @return const char* - returns a pointer to an interal dynamically generated buffer of XML that represents what this object contains
    */
    const char * getXMLFormatted() const;

    /**
    * Assigns a value to a tag.
    *
    * @param szComp const char * szComp
    * @return bool
    */
    XMLTag& operator=(const char * szComp);

    /**
    * Assigns the content of the tag reference passed in.
    *
    * @param tag XMLTag&
    * @return bool
    */
    XMLTag& operator=(const XMLTag & tag);

    /**
    * This is a debatable operator: Should it compare name or value?
    * It currently compares its value if it has one.
    * If there is no value it compares the name.
    *
    * @param szComp const char * szComp
    * @return bool
    */
    bool operator==(const char * szComp);

    /**
    * This too, is a debatable operator: Should it compare name or value?
    * It currently compares to its value if it has one.
    * If there is no value it compares to the name.
    *
    * @param szComp const char * szComp
    * @return bool
    */
    bool operator!=(const char * szComp);

    /**
    * This recursively compares the names and values
    * of the tags and attribute of an XMLTag instance to this one.
    *
    * @param tag const XMLTag &tag
    * @return bool
    */
    bool operator==(const XMLTag &tag) const;

    /**
    * This calls operator==( XMLTag &tag ) logically inverted.
    *
    * @param tag const XMLTag &tag
    * @return bool
    */
    bool operator !=(XMLTag &tag);

    /**
    * returns the path relative to the main known parent of the node
    *
    *
    * @return std::string
    */
    const std::string path() const;


    /**
    * returns the path relative to the main known parent of the node
    *
    * @param strTagPath - relative path of tag to obtain
    * NOTE: '#' place markers are use to indicate additional counter args (ie, path( "first/#/item", vec ).value()  )
    * @return XMLTag&
    */
    XMLTag& path(const std::string strTagPath, std::vector<int>vecVals);


    /**
    * returns the path relative to the main known parent of the node
    *
    * @param strTagPath - relative path of tag to obtain
    * NOTE: '#' place markers are use to indicate additional counter args (ie, path( "first/#/item/#", i, j ).value()  )
    * @return XMLTag&
    */
    XMLTag& path(const std::string strTagPath, ...);


    /**
    * returns true if the path relative to the main known parent of the node exists
    *
    * @param strTagPath - relative path of tag to obtain
    * NOTE: '#' place markers are use to indicate additional counter args (ie, path( "first/#/item/#", i, j )  )
    * @return XMLTag&
    */
    bool    hasPath(const std::string strTagPath, ...);


    /**
    * returns the path relative to the main known parent of the node
    *
    * @param strTagPath - relative path of tag to create
    * NOTE: '#' place markers are use to indicate additional counter args (ie, path( "first/#/item/create", i ).setValue("Hello");  )
    * @return XMLTag&
    */
    XMLTag& buildPath(const std::string strTagPath, ...);


    XMLTag& addPath(const std::string strTagPath, ...);


    /**
    * Index operator; provides access to a child tag by name.
    * If a tag contains multiple children of the same name
    * (which is common in XML) the first child with that name
    * is returned.
    *
    * @param szTagName const std::string with name of child tag
    * @return Returns a reference to the requested child tag.  If the tag does not exist, it returns a reference to an internal bogus tag to prevent applications from crashing.
    *
    *           A "strictness" flag will be added later to cause
    *           the class to throw an exception if a tag is
    *           requested that is not present.
    */
    XMLTag& operator[](const std::string strTagName) const;


    /**
    * Index operator; provides access to a child tag by name.
    * If a tag contains multiple children of the same name
    * (which is common in XML) the first child with that name
    * is returned.
    *
    * @param szTagName const char* pointer to name of child tag
    * @return Returns a reference to the requested child tag.  If the tag does not exist, it returns a reference to an internal bogus tag to prevent applications from crashing.
    *
    *           A "strictness" flag will be added later to cause
    *           the class to throw an exception if a tag is
    *           requested that is not present.
    */
    XMLTag& operator[](const char * szTagName) const;


    XMLTag& getTag(const std::string strTagName);


    XMLTag& getTag(const char * szTagName);

    /**
    * Index operator; provides access to a child tag by index position.
    * This is useful for tags that contain multiple tag entries of the
    * same name.  When a tag name or specification is unknown this method
    * will be the only way to access a tag a discover its details.
    *
    * @param iTagIndex
    * @return Returns a reference to the requested child tag.  If the index goes out of bounds, it returns a reference to an internal bogus tag to prevent applications from crashing.
    *
    *           A "strictness" flag will be added later to cause the
    *           class to throw an exception if a tag is requested
    *           that is not present.
    */
    XMLTag& operator[](size_t iTagIndex) const;


    XMLTag& getTag(size_t iTagIndex);

    /**
    * Returns a pointer to the parent tag.  Used internally for tag reference depth.
    *
    * @return XMLTag pointer
    */
    XMLTag* parent(); // pointer to parent tag

    /**
    * Returns a pointer to the null terminated buffer used internally to parse the XML.
    *
    * @return const char* to the buffer
    */
    const char* buffer();

    /**
    * Returns the size in bytes of buffer used internally to parse the XML.
    *
    * @return int size of internal buffer
    */
    int buffer_size();

    /**
    * Returns the number of child tag in this tag.
    *
    * @return int count of children
    */
    int count() const;

    /**
    * Returns the number of attributes for this tag.
    *
    * @return int count of attributes
    */
    int attribute_count() const;    // the numebr of attributes in this tag



    /**
    * Added a child to this tag that contain the XML in the strXML param.
    * Use insertXML for multiple XML tags non-nested
    * @param Tag    std::string (or a char *)
    * @return Returns a refernce to the child tag stored.
    */
    XMLTag& addXML(std::string strXML);

    /**
    * Added a child to this tag.
    *
    * @param Tag    XMLTag*
    * @return Returns a reference to the child tag stored.
    */
    XMLTag& addTag(XMLTag *pTag);

    /**
    * Added a child to this tag.
    *
    * @param Tag    XMLTag
    * @return Returns a reference to the child tag stored.
    */
    XMLTag& addTag(XMLTag &Tag);

    /**
    * Added a child to this tag.
    *
    * @param szName - name of new child tag
    * @return Returns a refernce to the child tag stored.
    */
    XMLTag& addTag(const char* szName);

    /**
    * Added a child to this tag.
    *
    * @param szName - name of new child tag
    * @param szValue - Value of new child tag
    * @return Returns a refernce to the child tag stored.
    */
    XMLTag& addTag(const char* szName, const char* szValue);

    /**
    * Added a child to this tag.
    *
    * @param szName - name of new child tag
    * @param bValue - Value of new child tag
    * @return Returns a refernce to the child tag stored.
    */
    XMLTag& addTag(const char* szName, bool bValue);

    /**
    * Added a child to this tag.
    *
    * @param szName - name of new child tag
    * @param intValue - Value of new child tag
    * @return Returns a refernce to the child tag stored.
    */
    XMLTag& addTag(const char* szName, int intValue);

    /**
    * Added a child to this tag.
    *
    * @param szName - name of new child tag
    * @param uintValue - Value of new child tag
    * @return Returns a refernce to the child tag stored.
    */
    XMLTag& addTag(const char* szName, unsigned int uintValue);

    /**
    * Added a child to this tag.
    *
    * @param szName - name of new child tag
    * @param floatValue - Value of new child tag
    * @return Returns a refernce to the child tag stored.
    */
    XMLTag& addTag(const char* szName, float floatValue);

    /**
    * Added a child to this tag.
    *
    * @param szName - name of new child tag
    * @param doubleValue - Value of new child tag
    * @return Returns a refernce to the child tag stored.
    */
    XMLTag& addTag(const char* szName, double doubleValue);

    /**
    * Added a child to this tag.
    *
    * @param strName - name of new child tag
    * @param strValue="" - Value of new child tag
    * @return Returns a refernce to the child tag stored.
    */
    XMLTag& addTag(std::string strName, std::string strValue = "");

    
    
    /**
    * Added one or more child tags to this tag that contain the XML in the strXML param.
    * 
    * @param strXML    std::string (or a char *)
    * @return void
    */
    void insertXML(std::string strXML);


    /**
    * Returns true if tag name is present inside this tag.
    *
    * @param szTagName
    *               const char* to the name of the tag
    * @return bool
    */
    bool hasTag(const char* szTagName) const;

    /**
    * Returns true if tag name is present inside this tag.
    *
    * @param strTagName
    *               std::string of the name of the tag
    * @return bool
    */
    bool hasTag(const std::string strTagName) const;

    bool deleteTag(std::string strName);
    bool deleteTag(const char * szName);

    /**
    * Returns the value assigned to this tag
    *
    * @return returns a std::string to allow easy use of its '==' comparison operator.
    */
    const std::string& value() const;

    /**
    * Returns the integer value assigned to this tag.   Calls atoi internally.
    *
    * @return returns an integer.
    */
    int intValue() const;

    /**
    * Returns the floating point value assigned to this tag.   Calls atof internally.
    *
    * @return returns a float.
    */
    float floatValue() const;

    /**
    * Returns the bool value assigned to this tag.  Comparison is always case insenitive.
    *
    * @return Returns true if value equals On, True, Hi, High, Yes, and any number other than zero.  Returns false for anything else
    */
    bool boolValue() const;

    /**
    * Sets the value of this tag to the contents of the char pointer passed in.
    *
    * @param szValue const char
    */
    void setValue(const char * szValue);

    /**
    * Sets the value of this tag to the contents of std::string passed in.
    *
    * @param szValue std::string
    */
    void setValue(std::string strValue);

    /**
    * Sets the value of this tag to the contents of the int passed in.
    *
    * @param iValue int
    */
    void setValue(int iValue);

    /**
    * Sets the value of this tag to the contents of unsigned int passed in.
    *
    * @param uiValue unsigned int
    */
    void setValue(unsigned int uiValue);

    /**
    * Sets the value of this tag to the contents of the float passed in.
    *
    * @param fValue unsigned int
    */
    void setValue(float fValue);

    /**
    * Sets the value of this tag to the contents of the float passed in.
    *
    * @param fValue unsigned int
    */
    void setValue(double dValue);

    /**
    * Returns the name of this tag
    *
    * @return returns a std::string to allow easy use of its '==' comparison operator.
    */
    const std::string& name() const;

    /**
    * Sets the name of this tag to the contents of the char pointer passed in.
    *
    * @param szTagName
    */
    void setName(const char * szTagName);

    /**
    * Sets the value of this tag to the contents of the std::string passed in.
    *
    * @param strValue std::string
    */
    void setName(std::string strTagName);

    /**
    * Returns the name of an attribute of this tag.
    *
    * @param iAttribute int value used for iterating through all attributes unknown or otherwise.
    * @return std::string
    */
    const std::string& attribute_name(int iAttibute) const;

    /**
    * Returns the interger value of an attribute of this tag.
    *
    * @param szAttribute name of attribute
    * @return int - value returned by atoi()
    */
    int intAttribute(std::string szAttribute) const;


    /**
    * Returns the boolean value of an attribute of this tag.
    *
    * Returns the bool value assigned to this tag.  Comparison is always case insenitive.
    *
    * @param szAttribute name of attribute
    * @return Returns true if value equals On, True, Hi, High, Yes, and any number other than zero.  Returns false for anything else
    */
    bool boolAttribute(const char* szAttribute) const;

    /**
    * Returns the value of an attribute of this tag.
    *
    * @param iAttribute int value used for iterating through all attributes unknown or otherwise.
    * @return std::string
    */
    const std::string& attribute(int iAttribute) const;

    /**
    * Returns the value of an attribute of this tag.
    *
    * @param szAttribute
    *               const char* to the name of the attribute
    * @return std::string
    */
    const std::string& attribute(std::string szAttribute) const;

    /**
    * Returns true if attribute name is present for this tag.
    *
    * @param szAttribute
    *               const char* to the name of the attribute
    * @return bool
    */
    bool hasAttribute(const char* szAttribute) const;

    /**
    * Sets an attribute and its value.
    *
    * @param szAttribute
    *                const char* to the attribute's name
    * @param szValue const char* to the attribute's value
    */
    void setAttribute(const char* szAttribute, const char* szValue);


    /**
    * Sets an attribute and its value.
    *
    * @param szAttribute
    *                const char* to the attribute's name
    * @param intValue  - the attribute's int value
    */
    void setAttribute(const char* szAttribute, int intValue);

    /**
    * Sets an attribute and its value.
    *
    * @param strAttribute
    *                 std::string of attribute's name
    * @param strValue std::string of attribute's value
    */
    void setAttribute(std::string strAttribute, std::string strValue);

    /**
    * Returns true if internal XML buffer is known to be incomplete.
    *
    * @return bool
    */
    bool incomplete()
    {
        return m_bIncomplete;
    }

    void sortFloat( std::string strSubTagPath );

    void swap(int pos1, int pos2);

};

#endif
