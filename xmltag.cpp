/*
   xmltag.cpp

   Class definition for XMLTag, a simple multi-platform xml parser
   that wraps the use and creation of XML into a single object.
   The internal parser is a single pass XML parser that is not only
   fast but allows for midstream parsing of XML data.  The class
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

#include "xmltag.h"

// XMLTag ******

#define iswhitespace(x)                                                        \
    (x == '\t' || x == ' ' || x == '\r' || x == '\n')

// used for case insensitivity
#define makelowercase(x) ((x >= 'A' && x <= 'Z') ? (x += 32) : x)

#include <cstdarg>

void XMLTag::init() {
    // m_szXMLBuffer = 0;
    // m_iXMLBufferSize = 0;
    m_fp = 0;

    m_tempbuf = 0;

    m_pUserBufferPointer = 0;
    m_iUserBufferSize = 0;

    m_bIncomplete = true;

    m_pBogus = 0;
    m_pParent = 0;
    m_TagName = "";
    m_Value = "";
    m_junk = "";
    m_ignoreCase = false;
    m_StrictMode = false;
}

XMLTag::XMLTag() { init(); }

XMLTag::XMLTag(const XMLTag &tag) {
    init();

    // if( tag.value().size() || tag.attribute_count() || tag.count() ||
    // tag.name().size() )
    {
        char *szXML = 0;
        tag.write(&szXML);
        this->read(szXML, strlen(szXML));
        delete[] szXML;
    }

    //    (*this) = tag;
}

XMLTag::XMLTag(XMLTag *pParent) {
    init();
    m_pParent = pParent;
}

XMLTag::XMLTag(const char *szTagName, const char *szValue) {
    init();
    m_TagName = szTagName;
    setValue(szValue);
}

XMLTag::XMLTag(const char *szTagName, bool bValue) {
    init();
    m_TagName = szTagName;
    m_Value = bValue ? "true" : "false";
}

XMLTag::XMLTag(const char *szTagName, int intValue) {
    init();
    m_TagName = szTagName;

    char szValue[255];
    sprintf(szValue, "%d", intValue);
    m_Value = szValue;
}

XMLTag::XMLTag(const char *szTagName, unsigned int uintValue) {
    init();
    m_TagName = szTagName;

    char szValue[255];
    sprintf(szValue, "%u", uintValue);
    m_Value = szValue;
}

XMLTag::XMLTag(const char *szTagName, float floatValue) {
    init();
    m_TagName = szTagName;

    char szValue[255];
    sprintf(szValue, "%f", floatValue);
    m_Value = szValue;
}

XMLTag::XMLTag(const char *szTagName, double doubleValue) {
    init();
    m_TagName = szTagName;

    char szValue[255];
    sprintf(szValue, "%f", doubleValue);
    m_Value = szValue;
}

XMLTag::XMLTag(const char *szTagName) {
    init();
    m_TagName = szTagName;
}

XMLTag::XMLTag(std::string strTagName, std::string strValue) {
    init();
    m_TagName = strTagName;
    setValue(strValue.c_str());
}

XMLTag::~XMLTag() {
    // if( parent() == NULL ) printf("x");

    // if( m_szXMLBuffer != 0 ) delete [] ( m_szXMLBuffer );

    delete m_pBogus;

    delete[] m_tempbuf;

    for (size_t i = 0; i < m_vecXMLTags.size(); i++)
        delete m_vecXMLTags[i];

    // this printf worked as expected
    // all nested tags were destroyed
    // indicating no memery leaks
    // printf("Destruction of %s complete\n", this->name().c_str() );
}

void XMLTag::clear() {
    for (size_t i = 0; i < m_vecXMLTags.size(); i++)
        delete m_vecXMLTags[i];

    m_vecXMLTags.clear();
    m_mapAttributes.clear();
    m_TagName.erase();
    m_Value.erase();

    m_szXMLBuffer.clear();

    delete m_pBogus;
    m_pBogus = 0;

}

void XMLTag::strictMode(bool bMode) { m_StrictMode = bMode; }

void XMLTag::ignoreCase(bool bIgnore) { m_ignoreCase = bIgnore; }

XMLTag &XMLTag::operator=(const char *szValue) {
    this->setValue(szValue);
    return *this;
}

XMLTag &XMLTag::operator=(const XMLTag &tag) {
    char *szXML = 0;
    tag.write(&szXML);
    this->read(szXML, strlen(szXML));
    delete[] szXML;

    return *this;
}

bool XMLTag::operator==(const char *szComp) {
    // Case insensitivity start
    int len = strlen(szComp);
    char *non_const_comp = (char *)malloc(len + 1);
    strcpy(non_const_comp, szComp);

    if (m_ignoreCase) {
        for (int i = 0; i < len; i++)
            makelowercase(non_const_comp[i]);
    }
    // Case insensitivity end

    if (m_Value.size()) {
        bool is_equal = (m_Value == non_const_comp);
        free(non_const_comp);
        return is_equal;
    } else {
        bool is_equal = (m_TagName == non_const_comp);
        free(non_const_comp);
        return is_equal;
    }
}

bool XMLTag::operator==(const XMLTag &tag) const {

    return !strcmp(tag.getXML(), this->getXML());

}

bool XMLTag::operator!=(XMLTag &tag) { return !((*this) == tag); }

bool XMLTag::operator!=(const char *szComp) {
    // Case insensitivity start
    int len = strlen(szComp);
    char *non_const_comp = (char *)malloc(len + 1);
    strcpy(non_const_comp, szComp);

    if (m_ignoreCase) {
        for (int i = 0; i < len; i++)
            makelowercase(non_const_comp[i]);
    }
    // Case insensitivity end

    if (m_Value.size()) {
        bool is_not_equal = (m_Value != non_const_comp);
        free(non_const_comp);
        return is_not_equal;
    } else {
        bool is_not_equal = (m_TagName != non_const_comp);
        free(non_const_comp);
        return is_not_equal;
    }
}

XMLTag &XMLTag::path(const std::string strTagPath, std::vector<int> vecVals) {
    std::string strElement;
    XMLTag *ref = this;
    int v = 0;

    int len = strTagPath.length();
    for (int i = 0; i < len; i++) {
        if (strTagPath[i] == '/') {
            if (strElement.length() > 0) {
                ref = &((*ref)[strElement]);
                strElement = "";
            }
        } else if (strTagPath[i] == '#') {
            ref = &(const_cast<XMLTag &>((*ref)[vecVals[v++]])); // should catch
            // vector limit here
        } else {
            strElement += strTagPath[i];
            if (i == len - 1) {
                ref = &((*ref)[strElement]);
            }
        }
    }

    return *ref;
}

const std::string XMLTag::path() const {
    std::string strPath(this->name());

    XMLTag *p = const_cast<XMLTag *>(this);
    while ((p = const_cast<XMLTag *>(p->parent())) != NULL) {
        strPath = p->name() + "/" + strPath;
    }

    return strPath;
}

// tag.path("costs/#/data/#/price", i, j );
XMLTag &XMLTag::path(const std::string strTagPath, ...) {
    va_list ap;
    va_start(ap, strTagPath);

    std::string strElement;
    XMLTag *ref = this;
    int len = strTagPath.length();

    for (int i = 0; i < len; i++) {
        if (strTagPath[i] == '/') {
            if (strElement.length() > 0) {
                ref = &(const_cast<XMLTag &>((*ref)[strElement]));
                strElement = "";
            }
        } else if (strTagPath[i] == '#') {
            ref = &(const_cast<XMLTag &>((*ref)[(int)va_arg(ap, int)]));
        } else {
            strElement += strTagPath[i];
            if (i == len - 1) {
                ref = &(const_cast<XMLTag &>((*ref)[strElement]));
            }
        }
    }

    va_end(ap);
    return *ref;
}

bool XMLTag::hasPath(const std::string strTagPath, ...) {
    va_list ap;
    va_start(ap, strTagPath);

    std::string strElement;
    XMLTag *ref = this;
    int len = strTagPath.length();

    try
    {
        
        for (int i = 0; i < len; i++) {
            if (strTagPath[i] == '/') {
                if (strElement.length() > 0) {
                    ref = &(const_cast<XMLTag &>((*ref)[strElement]));
                    strElement = "";
                }
            } else if (strTagPath[i] == '#') {
                ref = &(const_cast<XMLTag &>((*ref)[(int)va_arg(ap, int)]));
            } else {
                strElement += strTagPath[i];
                if (i == len - 1) {
                    ref = &(const_cast<XMLTag &>((*ref)[strElement]));
                }
            }
        }
    }
    catch(XMLTagException &e)
    {
        return false;
    }

    va_end(ap);
    
    return true;
}

XMLTag &XMLTag::buildPath(const std::string strTagPath, ...) {
    va_list ap;
    va_start(ap, strTagPath);

    std::string strElement;
    XMLTag *ref = this;
    int len = strTagPath.length();
    int depth = 0;

    for (int i = 0; i < len; i++) {
        if (strTagPath[i] == '/') {
            if (strElement.length() > 0) {
                if (depth == 0) {
                    setName(strElement);
                    ref = this;
                } else if (!(*ref).hasTag(strElement)) {
                    (*ref).addTag(strElement);
                    ref = &(const_cast<XMLTag &>((*ref)[strElement]));
                } else
                    ref = &(const_cast<XMLTag &>((*ref)[strElement]));

                strElement = "";
            }
            depth++;
        } else if (strTagPath[i] == '#') {
            ref = &(const_cast<XMLTag &>((*ref)[(int)va_arg(ap, int)]));
        } else {
            strElement += strTagPath[i];
            if (i == len - 1) {
                if (!(*ref).hasTag(strElement))
                    (*ref).addTag(strElement);

                ref = &(const_cast<XMLTag &>((*ref)[strElement]));
            }
        }
    }

    va_end(ap);
    return *ref;
}

XMLTag &XMLTag::addPath(const std::string strTagPath, ...) {
    va_list ap;
    va_start(ap, strTagPath);

    std::string strElement;
    XMLTag *ref = this;
    int len = strTagPath.length();
    int depth = 0;

    for (int i = 0; i < len; i++) {
        if (strTagPath[i] == '/') {
            if (strElement.length() > 0) {
                if (depth == 0) {
                    setName(strElement);
                    ref = this;
                } else if (!(*ref).hasTag(strElement)) {
                    (*ref).addTag(strElement);
                    ref = &(const_cast<XMLTag &>((*ref)[strElement]));
                } else
                    ref = &(const_cast<XMLTag &>((*ref)[strElement]));

                strElement = "";
            }
            depth++;
        } else if (strTagPath[i] == '#') {
            ref = &(const_cast<XMLTag &>((*ref)[(int)va_arg(ap, int)]));
        } else {
            strElement += strTagPath[i];
            if (i == len - 1) {
                ref = &(*ref).addTag(strElement);
            }
        }
    }

    va_end(ap);
    return *ref;
}

XMLTag &XMLTag::operator[](const std::string strTagName) const {
    return this->operator[](strTagName.c_str());
}

XMLTag &XMLTag::operator[](const char *szTagName) const {
    // Case insensitivity start
    int len = strlen(szTagName);
    char *non_const_comp = new char[len + 1];
    // memset( non_const_comp, 0, len+1 );
    strcpy(non_const_comp, szTagName);

    if (m_ignoreCase) {
        for (int i = 0; i < len; i++)
            makelowercase(non_const_comp[i]);
    }
    // Case insensitivity end

    int count;
    if ((count = m_vecXMLTags.size()) != 0) {

        for (int i = 0; count > i; i++) {
            // printf( "\t%s : %s\n", m_vecXMLTags[i]->name().c_str(), non_const_comp
            // );
            // if( m_vecXMLTags[i]->name() == non_const_comp )
            if (!strcmp(m_vecXMLTags[i]->name().c_str(), non_const_comp)) {
                delete[] non_const_comp;
                return *m_vecXMLTags[i];
            }
        }
    }

    delete[] non_const_comp;

    XMLTagException x;
    x.msg = "There is no tag with that name";
    x.sample = szTagName;
    x.sample += " ";
    x.sample += "does not exist";
    throw x;
}

XMLTag &XMLTag::getTag(const std::string strTagName) {
    return this->getTag(strTagName.c_str());
}

XMLTag &XMLTag::getTag(const char *szTagName) {
    // Case insensitivity start
    int len = strlen(szTagName);
    char *non_const_comp = new char[len + 1];
    // memset( non_const_comp, 0, len+1 );
    strcpy(non_const_comp, szTagName);

    if (m_ignoreCase) {
        for (int i = 0; i < len; i++)
            makelowercase(non_const_comp[i]);
    }
    // Case insensitivity end

    int count;
    if ((count = m_vecXMLTags.size()) != 0) {

        for (int i = 0; count > i; i++) {
            // printf( "\t%s : %s\n", m_vecXMLTags[i]->name().c_str(), non_const_comp
            // );
            // if( m_vecXMLTags[i]->name() == non_const_comp )
            if (!strcmp(m_vecXMLTags[i]->name().c_str(), non_const_comp)) {
                delete[] non_const_comp;
                return *m_vecXMLTags[i];
            }
        }
    }

    delete[] non_const_comp;

    XMLTagException x;
    x.msg = "There is no tag with that name";
    x.sample = szTagName;
    x.sample += " ";
    x.sample += "does not exist";
    throw x;
}

XMLTag &XMLTag::operator[](size_t iTagIndex) const {
    if (iTagIndex < m_vecXMLTags.size()) {
        return ((*m_vecXMLTags[iTagIndex]));
    } else {
        char sample[512];
        if (m_vecXMLTags.size() == 1) {
            sprintf(sample, "There is only 1 tag in this zero based index; "
                    "there is no item %zu",
                    iTagIndex);
        } else {
            sprintf(sample, "There are %zu tags in this zero based index; "
                    "there is no item %zu",
                    m_vecXMLTags.size(), iTagIndex);
        }

        XMLTagException x;
        x.msg = "Index out of bounds";
        x.sample = sample;
        throw x;
    }
}

XMLTag &XMLTag::getTag(size_t iTagIndex) {
    if (iTagIndex < m_vecXMLTags.size()) {
        return ((*m_vecXMLTags[iTagIndex]));
    } else {
        char sample[512];
        if (m_vecXMLTags.size() == 1) {
            sprintf(sample, "There is only 1 tag in this zero based index; "
                    "there is no item %zu",
                    iTagIndex);
        } else {
            sprintf(sample, "There are %zu tags in this zero based index; "
                    "there is no item %zu",
                    m_vecXMLTags.size(), iTagIndex);
        }

        XMLTagException x;
        x.msg = "Index out of bounds";
        x.sample = sample;
        throw x;
    }
}

XMLTag *XMLTag::parent() { return m_pParent; }

int XMLTag::count() const { return m_vecXMLTags.size(); }

int XMLTag::attribute_count() const { return m_mapAttributes.size(); }

XMLTag &XMLTag::addXML(std::string strXML) {
    XMLTag *pXmlTemp = new XMLTag(this);

    m_vecXMLTags.push_back(pXmlTemp);

    pXmlTemp->read(strXML.c_str(), strXML.size());

    return *pXmlTemp;
}

void XMLTag::insertXML(std::string strXML) {
    
    int pos = 0;
    int len = strXML.size();
    
    while( pos < len )
    {
        XMLTag *pXmlTemp = new XMLTag(this);

        pos += pXmlTemp->read( &(strXML.c_str()[pos]), len-pos );

        m_vecXMLTags.push_back( pXmlTemp );

    }
    
}

XMLTag &XMLTag::addTag(XMLTag *pTag) {

    m_vecXMLTags.push_back(pTag);

    pTag->m_pParent = this;

    return *m_vecXMLTags[m_vecXMLTags.size() - 1];
}

XMLTag &XMLTag::addTag(XMLTag &Tag) {
    XMLTag *pXmlTemp = new XMLTag(this);

    m_vecXMLTags.push_back(pXmlTemp);

    char *szXML = 0;
    Tag.write(&szXML);

    // printf("%s\n", szXML );

    pXmlTemp->read(szXML);

    delete[] szXML;

    return *pXmlTemp;
}

XMLTag &XMLTag::addTag(const char *szName) {
    return addTag(new XMLTag(szName));
}

XMLTag &XMLTag::addTag(const char *szName, const char *szValue) {
    return addTag(new XMLTag(szName, szValue));
}

XMLTag &XMLTag::addTag(const char *szName, bool bValue) {
    return addTag(new XMLTag(szName, bValue));
}

XMLTag &XMLTag::addTag(const char *szName, int intValue) {
    return addTag(new XMLTag(szName, intValue));
}

XMLTag &XMLTag::addTag(const char *szName, unsigned int uintValue) {
    return addTag(new XMLTag(szName, uintValue));
}

XMLTag &XMLTag::addTag(const char *szName, float floatValue) {
    return addTag(new XMLTag(szName, floatValue));
}

XMLTag &XMLTag::addTag(const char *szName, double doubleValue) {
    return addTag(new XMLTag(szName, doubleValue));
}

XMLTag &XMLTag::addTag(std::string strName, std::string strValue) {
    return addTag(new XMLTag(strName, strValue));
}

bool XMLTag::deleteTag(std::string strName) {
    return deleteTag(strName.c_str());
}

bool XMLTag::deleteTag(const char *szName) {
    std::vector<XMLTag *>::iterator it;

    for (it = m_vecXMLTags.begin(); it != m_vecXMLTags.end(); it++) {
        if ((*it)->name() == szName) {
            m_vecXMLTags.erase(it);
            delete (*it);
            return true;
        }
    }

    return false;
}

const std::string &XMLTag::value() const {
    // return const_cast<std::string>(m_Value);
    return m_Value;
}

int XMLTag::intValue() const { return atoi(this->value().c_str()); }

float XMLTag::floatValue() const { return atof(this->value().c_str()); }

bool XMLTag::boolValue() const {
    // Case insensitivity start
    int len = this->value().size();

    if (len == 0)
        return false;

    char *non_const_copy = (char *)malloc(len + 1);
    strcpy(non_const_copy, this->value().c_str());

    for (int i = 0; i < len; i++)
        makelowercase(non_const_copy[i]);
    // Case insensitivity end

    if (!strcmp(non_const_copy, "true") || !strcmp(non_const_copy, "yes") ||
            !strcmp(non_const_copy, "hi") || !strcmp(non_const_copy, "on") ||
            !strcmp(non_const_copy, "high") || (atoi(non_const_copy) != 0)) {
        free(non_const_copy);
        return true;
    } else {
        free(non_const_copy);
        return false;
    }
}

void XMLTag::setValue(const char *szValue) {
    m_Value = szValue;
}

void XMLTag::setValue(std::string strValue) { setValue(strValue.c_str()); }

void XMLTag::setValue(int iValue) {
    char temp[32];
    sprintf(temp, "%d", iValue);
    m_Value = temp;
}

void XMLTag::setValue(unsigned int uiValue) {
    char temp[32];
    sprintf(temp, "%u", uiValue);
    m_Value = temp;
}

void XMLTag::setValue(float fValue) {
    char temp[32];
    sprintf(temp, "%f", fValue);
    m_Value = temp;
}

void XMLTag::setValue(double dValue) {
    char temp[32];
    sprintf(temp, "%f", dValue);
    m_Value = temp;
}

const std::string &XMLTag::name() const { return m_TagName; }

void XMLTag::setName(const char *szTagName) {
    // Case insensitivity start
    int len = strlen(szTagName);
    char *non_const_comp = (char *)malloc(len + 1);
    strcpy(non_const_comp, szTagName);

    if (m_ignoreCase) {
        for (int i = 0; i < len; i++)
            makelowercase(non_const_comp[i]);
    }
    // Case insensitivity end

    m_TagName = non_const_comp;
    free(non_const_comp);
}

void XMLTag::setName(std::string strTagName) {
    // Case insensitivity start
    int len = strTagName.size();
    char *non_const_comp = (char *)malloc(len + 1);
    strcpy(non_const_comp, strTagName.c_str());

    if (m_ignoreCase) {
        for (int i = 0; i < len; i++)
            makelowercase(non_const_comp[i]);
    }
    // Case insensitivity end

    m_TagName = strTagName;
    free(non_const_comp);
}

bool XMLTag::boolAttribute(const char *szAttribute) const {
    if (m_StrictMode) {
        std::map<std::string, std::string>::const_iterator it;
        it = m_mapAttributes.find(szAttribute);
        if (it == m_mapAttributes.end()) {
            XMLTagException x;
            x.msg = "There is no attribute with that name in tag <";
            x.msg = this->name() + ">";

            x.sample = szAttribute;
            x.sample += " ";
            x.sample += " attribute does not exist in this tag";
            throw x;
        }
    }

    // Case insensitivity start
    int len = this->attribute(szAttribute).size();

    if (len == 0)
        return false;

    char *non_const_copy = (char *)malloc(len + 1);
    strcpy(non_const_copy, this->attribute(szAttribute).c_str());

    for (int i = 0; i < len; i++)
        makelowercase(non_const_copy[i]);
    // Case insensitivity end

    if (!strcmp(non_const_copy, "true") || !strcmp(non_const_copy, "yes") ||
            !strcmp(non_const_copy, "hi") || !strcmp(non_const_copy, "ok") ||
            !strcmp(non_const_copy, "on") || !strcmp(non_const_copy, "high") ||
            (atoi(non_const_copy) != 0)) {
        free(non_const_copy);
        return true;
    } else {
        free(non_const_copy);
        return false;
    }
}

int XMLTag::intAttribute(std::string szAttribute) const {
    if (m_StrictMode) {
        std::map<std::string, std::string>::const_iterator it;
        it = m_mapAttributes.find(szAttribute.c_str());
        if (it == m_mapAttributes.end()) {
            XMLTagException x;
            x.msg = "There is no attribute with that name in tag <";
            x.msg = this->name() + ">";

            x.sample = szAttribute;
            x.sample += " ";
            x.sample += " attribute does not exist in this tag";
            throw x;
        }
    }
    return atoi(this->attribute(szAttribute).c_str());
}

const std::string &XMLTag::attribute(std::string szAttribute) const {
    if (m_StrictMode) {
        std::map<std::string, std::string>::const_iterator it;
        it = m_mapAttributes.find(szAttribute);
        if (it == m_mapAttributes.end()) {
            XMLTagException x;
            x.msg = "There is no attribute with that name in tag <";
            x.msg = this->name() + ">";

            x.sample = szAttribute;
            x.sample += " ";
            x.sample += " attribute does not exist in this tag";
            throw x;
        }
    }

    // return m_mapAttributes[szAttribute];

    std::map<std::string, std::string>::const_iterator it;
    it = m_mapAttributes.find(szAttribute);
    if (it == m_mapAttributes.end()) {
        // const_cast<std::string>(m_junk) = "";
        return m_junk;
    } else {
        return it->second;
    }
}

const std::string &XMLTag::attribute(int iAttribute) const {
    std::map<std::string, std::string>::const_iterator it =
        m_mapAttributes.begin();

    for (int i = 0; i < iAttribute; i++, it++) {
        if (it == m_mapAttributes.end()) {
            if (m_StrictMode) {
                char sample[512];
                if (m_mapAttributes.size() == 1) {
                    sprintf(sample, "There is only 1 attribute in this zero based index; "
                            "there is no item %d",
                            iAttribute);
                } else {
                    sprintf(sample, "There are %zu attributes in this zero based index; "
                            "there is no item %d",
                            m_mapAttributes.size(), iAttribute);
                }

                XMLTagException x;
                x.msg = "Index out of bounds";
                x.sample = sample;
                throw x;
            } else {
                // printf("\nXMLTag: returning junk\n");
                return m_junk;
            }
        }
    }

    return it->second;
}

const std::string &XMLTag::attribute_name(int iAttribute) const {
    std::map<std::string, std::string>::const_iterator it =
        m_mapAttributes.begin();

    for (int i = 0; i < iAttribute; i++, it++) {
        if (it == m_mapAttributes.end()) {
            if (m_StrictMode) {
                char sample[512];
                if (m_mapAttributes.size() == 1) {
                    sprintf(sample, "There is only 1 attribute in this zero based index; "
                            "there is no item %d",
                            iAttribute);
                } else {
                    sprintf(sample, "There are %zu attributes in this zero based index; "
                            "there is no item %d",
                            m_mapAttributes.size(), iAttribute);
                }

                XMLTagException x;
                x.msg = "Index out of bounds";
                x.sample = sample;
                throw x;
            } else {
                return m_junk;
            }
        }
    }

    return it->first;
}

void XMLTag::setAttribute(const char *szAttribute, const char *szValue) {
    // Case insensitivity start
    int len = strlen(szAttribute);
    char *non_const_copy = (char *)malloc(len + 1);
    strcpy(non_const_copy, szAttribute);

    if (m_ignoreCase) {
        for (int i = 0; i < len; i++)
            makelowercase(non_const_copy[i]);
    }
    // Case insensitivity end

    m_mapAttributes[non_const_copy] = szValue;
    free(non_const_copy);
}

void XMLTag::setAttribute(const char *szAttribute, int intValue) {
    // Case insensitivity start
    int len = strlen(szAttribute);
    char *non_const_copy = (char *)malloc(len + 1);
    strcpy(non_const_copy, szAttribute);

    if (m_ignoreCase) {
        for (int i = 0; i < len; i++)
            makelowercase(non_const_copy[i]);
    }
    // Case insensitivity end

    char szValue[255];
    sprintf(szValue, "%d", intValue);
    m_mapAttributes[non_const_copy] = szValue;
    free(non_const_copy);
}

void XMLTag::setAttribute(std::string strAttribute, std::string strValue) {
    // Case insensitivity start
    int len = strAttribute.size();
    char *non_const_copy = (char *)malloc(len + 1);
    strcpy(non_const_copy, strAttribute.c_str());

    if (m_ignoreCase) {
        for (int i = 0; i < len; i++)
            makelowercase(non_const_copy[i]);
    }
    // Case insensitivity end

    m_mapAttributes[strAttribute] = strValue;
    free(non_const_copy);
}

bool XMLTag::hasAttribute(const char *szAttribute) const {
    std::map<std::string, std::string>::const_iterator it;
    it = m_mapAttributes.find(szAttribute);
    if (it == m_mapAttributes.end()) {
        return false;
    }

    return true;
}

bool XMLTag::hasTag(const std::string strTagName) const {
    return hasTag(strTagName.c_str());
}

bool XMLTag::hasTag(const char *szTagName) const {
    // Case insensitivity start
    int len = strlen(szTagName);
    char *non_const_comp = (char *)malloc(len + 1);
    strcpy(non_const_comp, szTagName);

    if (m_ignoreCase) {
        for (int i = 0; i < len; i++)
            makelowercase(non_const_comp[i]);
    }
    // Case insensitivity end

    int count;
    if ((count = m_vecXMLTags.size()) != 0) {
        for (int i = 0; count > i; i++) {
            if (m_vecXMLTags[i]->name() == non_const_comp) {
                free(non_const_comp);
                return true;
            }
        }
    }

    free(non_const_comp);
    return false;
}


bool XMLTag::getNextByte(char *pByte) {
    XMLTagException x;

    if (m_fp != 0) {
        *pByte = fgetc(m_fp);

        if (feof(m_fp))
            return false;
    } 
    else {
        throw x;
    }

    return true;
}

bool XMLTag::parse() {
    // if( !m_bIncomplete )
    this->clear();

    // m_bIncomplete = true;

    // m_szXMLBuffer = (char*)malloc(XML_BUFFER_BLOCK_SIZE);
    // m_szXMLBuffer = new char [XML_BUFFER_BLOCK_SIZE];
    m_szXMLBuffer.clear();

    XMLTagException x; // for exception throwing

    bool bTagBracketOpen = false; // true if inside tag bracket
    bool bOpeningTag = true;      // true if on opening tag
    bool bOpenCloseTag = false;
    bool bGetAttributes = false;            // true if getting attributes
    bool bAttributeValueAssignment = false; // true if attrib "="
    bool bOpenQuote = false;                // Used to track attribute quotes
    bool bEntity = false;
    // bool            bIncomplete = true; // true if incomplete
    bool bComment = false;
    int iCounter = 0;           // depth counter
    XMLTag *pCurrentTag = this; // parent of child reference

    std::map<std::string, std::string> tmp_mapAttributes;
    std::string TagText;
    std::string ValueText;
    std::string EntityText;
    std::string AttributeText;
    std::string AttributeValue;
    char byte = 0;
    int buffer_pos=0;
    // char     szValueText[128];
    // int     iValueTextPos = 0;

    // TODO: Determine if this really helps
       int len = 25;
       TagText.reserve( len );
       ValueText.reserve( len );
       EntityText.reserve( len );
       AttributeText.reserve( len );
       AttributeValue.reserve( len );
     

    //while (getNextByte(&byte)) {
    while ( true )
    {
        if( ( m_pUserBufferPointer != NULL) )
        {
            if( m_iUserBufferSize > buffer_pos )
            {
                if( ( byte = m_pUserBufferPointer[buffer_pos] ) == 0)
                    break;
            }
            else
            {
                break;
            }
        }
        else if( getNextByte(&byte) )
        {
            if( byte == 0 )
                break;
        }
        else
            break;
        
        buffer_pos++;
        m_szXMLBuffer.push_back( byte );
        // printf("%c", byte );
        if (byte == '<' && bTagBracketOpen == false) {
            bTagBracketOpen = true;

            // Just in case our entity data was not closed
            if (bEntity) {
                ValueText += EntityText;
                bEntity = false;
                EntityText = "";
            }

            continue;
        } else if (byte == '>' && bTagBracketOpen == true) {
            bTagBracketOpen = false;
            bGetAttributes = false;

            if (bComment) {
                bComment = false;
                continue;
            } else {
                if (AttributeText.size() && TagText.size()) {
                    // Either an attribute had no value or a tag name had a space

                    x.sample = "<";
                    x.sample += TagText + " " + AttributeText + ">";
                    x.msg = "Either a tag name had a space or an attribute had no value";
                    throw x;
                }

                // This was either a new(opening) tag or an Open/Close tag
                if (bOpeningTag == true || bOpenCloseTag == true) {
                    if (iCounter++ >= 1) {
                        // increment reference depth here
                        pCurrentTag = &(pCurrentTag->addTag(new XMLTag(pCurrentTag)));
                        pCurrentTag->ignoreCase(m_ignoreCase);
                        pCurrentTag->strictMode(m_StrictMode);
                    }

                    // fill new tag with attributes attained
                    {
                        std::map<std::string, std::string>::iterator it;

                        for (it = tmp_mapAttributes.begin(); it != tmp_mapAttributes.end();
                                it++)
                            pCurrentTag->setAttribute(it->first, it->second);

                        tmp_mapAttributes.clear();
                    }

                    pCurrentTag->setName(TagText);
                }

                // This was either a closing tag or an Open/Close tag
                if (bOpeningTag == false ||
                        bOpenCloseTag == true) // This was a closing tag
                {
                    iCounter--;

                    if (pCurrentTag->name() == TagText) {
                        // ValueText += szValueText;

                        pCurrentTag->setValue(ValueText);
                        ValueText.erase();
                        bOpenCloseTag = false; // all done with this tag

                        if (pCurrentTag == this) {
                            m_bIncomplete = false; // this is a redundant measure

                            // this break prevents additional reading
                            // from the descriptor in use
                            break;
                        }

                        // decrement reference depth here
                        if (pCurrentTag != pCurrentTag->parent())
                            pCurrentTag = pCurrentTag->parent();
                    } else {
                        x.sample = "<";
                        x.sample += pCurrentTag->name();
                        x.sample += "> and </";
                        x.sample += TagText + ">";
                        x.msg = "A closing tag does not match its opening tag";

                        throw x;
                    }
                }

                TagText.erase();
                bOpeningTag = true;
                continue;
            }
        } else if (byte == 0) {
            return false;
        } else {
            if (bTagBracketOpen) {
                if (bComment)
                    continue;

                if (!bOpenQuote && (byte == '?' || byte == '!')) {
                    if (TagText.size() == 0) {
                        bComment = true;
                        continue;
                    } else {
                        x.sample = "<";
                        x.sample += TagText;
                        x.sample += "/>";

                        x.msg = "Invalid character in tag";
                        throw x;
                    }

                } else if (byte == '/' && !(bAttributeValueAssignment)) {
                    if (TagText.size() != 0)
                        bOpenCloseTag = true;

                    if (TagText.size() == 0)
                        bOpeningTag = false; // false means closing tag
                } else {
                    if (bOpenCloseTag) {
                        // if we got here the tag was an
                        // open and closing tag and there
                        // were characters received after
                        // the '/'

                        x.sample = "<";
                        x.sample += TagText;
                        x.sample += "/>";

                        x.msg = "An invalid OpenClosing";
                        throw x;
                    } else if (iswhitespace(byte) || byte == '\"') {
                        // when we hit a white space here it might
                        // be due to the presence of attributes
                        // so here is where they will be handled

                        if (TagText.size()) {
                            bGetAttributes = true;

                            if (AttributeText.size()) {
                                if (AttributeValue.size() &&
                                        (bOpenQuote == true && iswhitespace(byte))) {
                                    AttributeValue += ' ';
                                } else if (AttributeValue.size() ||
                                        (bOpenQuote == true && byte == '\"')) {
                                    // pCurrentTag->setAttribute( AttributeText, AttributeValue );
                                    tmp_mapAttributes[AttributeText] = AttributeValue;
                                    AttributeText.erase();
                                    AttributeValue.erase();
                                    bAttributeValueAssignment = false;
                                    bOpenQuote = false;
                                } else if (byte == '\"') {
                                    if (!bOpenQuote) {
                                        bOpenQuote = true;
                                    } else {
                                        x.sample = "<";
                                        x.sample = TagText + " " + AttributeText + "=\"\">";
                                        x.msg = "The attribute of a tag contained no value";
                                        throw x;
                                    }
                                } else {
                                    if (bAttributeValueAssignment == false) {
                                        // if we are here there was
                                        // a white space after an
                                        // attribute before the equal
                                        x.sample = "<";
                                        x.sample += TagText + " " + AttributeText + ">";
                                        x.msg =
                                            "There was a space after an attribute before the \"=\"";
                                        throw x;
                                    }
                                }
                            }
                            continue;
                        } else {
                            // if we are here there is a white space
                            // before the tag text

                            x.msg = "There is a space before the text of a tag";
                            throw x;
                        }
                    } else if (byte == '=') {
                        if (TagText.size() && AttributeText.size() && bGetAttributes) {
                            bAttributeValueAssignment = true;
                            continue;
                        } else {
                            // if we are here there is an equal
                            // before the tag text or the attribute text
                            // neither of which is good.
                            if (TagText.size()) {
                                x.sample = "<";
                                x.sample += TagText;
                                x.sample += ">";
                            }
                            x.msg = "There is an \"=\" before a tag or attribute";
                            throw x;
                        }
                    }

                    if (!bGetAttributes) {
                        if (m_ignoreCase)
                            makelowercase(byte);

                        TagText += byte;
                    } else if (bGetAttributes) {
                        if (!bAttributeValueAssignment) {
                            if (m_ignoreCase)
                                makelowercase(byte);
                            AttributeText += byte;
                        } else {
                            AttributeValue += byte;
                        }
                    }

                    // if we're on a new tag we can
                    // delete the old value text
                    if (bOpeningTag == true) {
                        ValueText.erase();
                        // memset( szValueText, 0, sizeof( szValueText ) );
                        // iValueTextPos = 0;
                    }
                }
            } else if (!bTagBracketOpen && bOpeningTag) // Between tags
            {
                if (pCurrentTag->name().size() == 0) {
                    if (!iswhitespace(byte)) {
                        XMLTagException x;
                        x.msg = "The data being parsed does not seem to be XML";
                        throw x;
                    }
                }

                if (byte == '&')
                    bEntity = true;

                // if( iValueTextPos >= sizeof(szValueText) )
                //{
                //    ValueText += szValueText;
                //    memset( szValueText, 0, sizeof( szValueText ) );
                //    iValueTextPos = 0;
                //}

                if (bEntity) {
                    EntityText += byte;

                    if (byte == ';') {
                        bEntity = false;

                        /*
                           if( EntityText == "&lt;" )
                           szValueText[iValueTextPos++] =  '<';
                           else if( EntityText == "&gt;" )
                           szValueText[iValueTextPos++] =  '>';
                           else if( EntityText == "&amp;" )
                           szValueText[iValueTextPos++] =  '&';
                           else if( EntityText == "&quot;" )
                           szValueText[iValueTextPos++] =  '"';
                           else if( EntityText == "&apos;" )
                           szValueText[iValueTextPos++] =  '\'';
                           */

                        if (EntityText == "&lt;")
                            ValueText += '<';
                        else if (EntityText == "&gt;")
                            ValueText += '>';
                        else if (EntityText == "&amp;")
                            ValueText += '&';
                        else if (EntityText == "&quot;")
                            ValueText += '"';
                        else if (EntityText == "&apos;")
                            ValueText += '\'';
                        else
                            ValueText += EntityText;

                        EntityText = "";
                    }

                } else {
                    ValueText += byte;
                    // szValueText[iValueTextPos++] = byte;
                }
            }
        }
    }

    if (m_fp)
        if (feof(m_fp))
            return false;

    if (m_bIncomplete == true)
        return false;

    return true;
}

bool XMLTag::load(const char *szFileName) {
    if (szFileName == NULL || *szFileName == '\0')
        return false;

    bool bRet = true;

    FILE *fp = fopen(szFileName, "r");

    if (fp == NULL)
        return false;

    m_fp = fp;

    try {
        bRet = parse();
        m_fp = 0;
    }
    catch (XMLTagException x) {
        m_fp = 0;
        fclose(fp);
        throw x;
    }

    fclose(fp);

    return bRet;
}

bool XMLTag::store(const char *szFileName, bool bFormatted /* = false */) {
    if (szFileName == NULL || *szFileName == '\0')
        return false;

    FILE *fp = fopen(szFileName, "w");

    if (fp != NULL) {
        if (!bFormatted) {
            int size = generationByteCount();
            char *buf = new char[size + 1]; // new instead of malloc was only to shut
            // up the debugger
            generateXML(&buf);
            int ret = fwrite(buf, generationByteCount(), 1, fp);
            delete[] buf;
            fflush(fp);
            fclose(fp);

            if (ret)
                return true;
            else
                return false;
        } else {
            int size = generationByteCount(0);
            char *buf = new char[size + 1]; // new instead of malloc was only to shut
            // up the debugger
            generateXML(&buf, 0, 0);
            int ret = fwrite(buf, size, 1, fp);
            delete[] buf;
            fflush(fp);
            fclose(fp);

            if (ret)
                return true;
            else
                return false;
        }

    } else {
        return false;
    }
}

bool XMLTag::read(FILE *fp) {
    m_pUserBufferPointer = NULL;
    
    if (fp == NULL)
        return false;

    m_fp = fp;

    try {
        parse();
        m_fp = 0;
    }
    catch (XMLTagException x) {
        m_fp = 0;
        throw x;
    }

    return true;
}

int XMLTag::read(const char *pBuffer, int iBufferSize /* = 0 */) {
    if (pBuffer == NULL)
        return 0;

    m_pUserBufferPointer = pBuffer;

    if (iBufferSize == 0)
        m_iUserBufferSize = strlen(pBuffer);
    else
        m_iUserBufferSize = iBufferSize;

    if (m_iUserBufferSize == 0)
        return 0;

    try {
        parse();
        // m_pUserBufferPointer = 0;
        // m_iUserBufferSize = 0;
    }
    catch (XMLTagException x) {
        // m_pUserBufferPointer = 0;
        // m_iUserBufferSize = 0;
        throw x;
    }

    // return m_iUserBufferSize;
    return m_szXMLBuffer.size();
}

int XMLTag::write(FILE *fp) const {
    if (fp != NULL) {
        int size = generationByteCount();
        char *buf = new char[size + 1]; // new instead of malloc was only to shut up
        // the debugger
        generateXML(&buf);
        int ret = fwrite(buf, generationByteCount(), 1, fp);
        delete[] buf;

        if (ret)
            return size;
        else
            return 0;
    } else {
        return 0;
    }
}

int XMLTag::write(char **buf) const {
    if (buf != NULL) {
        int size = generationByteCount();
        *buf = new char[size + 1]; // new instead of malloc was only to shut up the
        // debugger
        generateXML(buf);

        return size;
    } else {
        return 0;
    }
}

const char *XMLTag::getXML() const {
    int size = generationByteCount();

    if (m_tempbuf)
        delete[] m_tempbuf;
    // const_cast<char*>(m_tempbuf) = new char[size+1]; // new instead of malloc
    // was only to shut up the debugger

    // void* buf = malloc( size+1 );
    m_tempbuf = new char[size + 1];

    // memcpy( const_cast<char**>(&m_tempbuf), &buf, sizeof(void*) );
    // memcpy( &m_tempbuf, &buf, sizeof(void*) );

    if (m_tempbuf)
        generateXML(&m_tempbuf);
    // generateXML( (const_cast<char**>(&m_tempbuf)) );
    else
        return NULL;

    return static_cast<const char *>(m_tempbuf);
}

const char *XMLTag::getXMLFormatted() const {
    int size = generationByteCount(0);

    if (m_tempbuf)
        delete m_tempbuf;
    m_tempbuf = new char[size + size + 1]; // new instead of malloc was only to
    // shut up the debugger

    if (m_tempbuf)
        generateXML(&m_tempbuf, 0, 0);
    else
        return NULL;

    // return m_tempbuf;
    return static_cast<const char *>(m_tempbuf);
}


int XMLTag::generationByteCount(int tabs /* = -1 */) const {
    int bytecount = 0;

    // Count tabs if we're using 'em
    if (tabs >= 0) {
        bytecount += (tabs * 2);
        tabs++; // increment for the recursive call below
    }

    // tag opening bracket and name
    bytecount += strlen("<");
    bytecount += name().size();

    // tag attribute stuff
    if (attribute_count()) {
        // iterate through attibutes
        for (int a = 0; a < attribute_count(); a++) {
            bytecount += strlen(" =\"\"");
            bytecount += (attribute_name(a).size() + attribute(a).size());
        }
    }

    if (value().size() || count()) // if this tag has values or tags.....
    {
        // Open tag closing bracket
        bytecount += strlen(">");

        // Tag value
        // bytecount += value().size();
        {
            const std::string &strValue = value();

            int len = strValue.size();

            for (int i = 0; i < len; i++) {
                char byte = strValue[i];

                if (byte == '<')
                    bytecount += strlen("&lt;");
                else if (byte == '>')
                    bytecount += strlen("&gt;");
                else if (byte == '&')
                    bytecount += strlen("&amp;");
                else if (byte == '\'')
                    bytecount += strlen("&apos;");
                else if (byte == '\"')
                    bytecount += strlen("&quot;");
                else {
                    bytecount++;
                }
            }
        }

        // Call (recurse) this method on all internal tags
        if (count() != 0) {
            for (int t = 0; t < count(); t++) {
                // Recursion starts here
                bytecount += operator[](t).generationByteCount(tabs);
            }
        }

        // Closing tag
        bytecount += strlen("</>");
        bytecount += name().size();
    } else // else if this tag has no tags or values.....
    {
        // closing bracket for an open/close tag
        bytecount += strlen("/>");
    }

    return bytecount;
}

int XMLTag::generateXML(char **genbuf, int pos /* = 0 */,
        int tabs /* = -1 */) const {
    // Format with tabs
    for (int i = tabs; i > 0; i--) {
        pos += sprintf(&(*genbuf)[pos], "\t");
    }

    // tag opening bracket and name
    pos += sprintf(&(*genbuf)[pos], "<%s", name().c_str());

    // tag attribute stuff
    if (attribute_count()) {
        // iterate through attibutes
        for (int a = 0; a < attribute_count(); a++) {
            pos += sprintf(&(*genbuf)[pos], " %s=\"%s\"", attribute_name(a).c_str(),
                    attribute(a).c_str());
        }
    }

    if (value().size() || count()) // if this tag has values or tags.....
    {
        // Open tag closing bracket
        pos += sprintf(&(*genbuf)[pos], ">");

        // Format with linefeeds
        if (tabs >= 0) {
            if (this->value() == "") {
                pos += sprintf(&(*genbuf)[pos], "\n");
            }
        }

        // Tag value
        if (value().size()) {
            const std::string &strValue = value();

            int len = strValue.size();

            for (int i = 0; i < len; i++) {
                char byte = strValue[i];

                if (byte == '<')
                    pos += sprintf(&(*genbuf)[pos], "%s", "&lt;");
                else if (byte == '>')
                    pos += sprintf(&(*genbuf)[pos], "%s", "&gt;");
                else if (byte == '&')
                    pos += sprintf(&(*genbuf)[pos], "%s", "&amp;");
                else if (byte == '\'')
                    pos += sprintf(&(*genbuf)[pos], "%s", "&apos;");
                else if (byte == '\"')
                    pos += sprintf(&(*genbuf)[pos], "%s", "&quot;");
                else {
                    (*genbuf)[pos++] = byte;
                }
            }
            // pos += sprintf( &(*genbuf)[pos], "%s", strValue().c_str() );
        }

        // Call (recurse) this method on all internal tags
        if (count() != 0) {
            for (int t = 0; t < count(); t++) {
                // Recursion starts here
                if (tabs < 0)
                    pos += operator[](t).generateXML(genbuf, pos) - pos;
                else
                    pos += operator[](t).generateXML(genbuf, pos, tabs + 1) - pos;
            }
        }

        // Format closing tag with tabs if there is no value
        if (this->value() == "") {
            for (int i = tabs - 1; i >= 0; i--) {
                pos += sprintf(&(*genbuf)[pos], "\t");
            }
        }

        // Closing tag
        pos += sprintf(&(*genbuf)[pos], "</%s>", name().c_str());

        // Format with linefeeds
        if (tabs >= 0) {
            pos += sprintf(&(*genbuf)[pos], "\n");
        }

    } else // else if this tag has no tags or values.....
    {
        // closing bracket for an open/close tag
        pos += sprintf(&(*genbuf)[pos], "/>");

        // Format with linefeeds
        if (tabs >= 0) {
            // if( this->value() == "" )
            {
                pos += sprintf(&(*genbuf)[pos], "\n");
            }
        }
    }

    return pos;
}

void XMLTag::sortFloat( std::string strSubTagPath )
{
	XMLTag &refParent = *this;
	int len = refParent.count();

	for( int i=0; i<(len-1); i++ )
	{
	    for( int j=0; j<(len-1); j++ )
		if( refParent[j].path(strSubTagPath).floatValue() > refParent[j+1].path(strSubTagPath).floatValue() )
		    refParent.swap(j, j+1);
	}
}

void XMLTag::swap(int pos1, int pos2)
{	
	if( pos1 < m_vecXMLTags.size() && pos2 < m_vecXMLTags.size() )
	{
	    XMLTag *p = m_vecXMLTags[pos1];
	    m_vecXMLTags[pos1] = m_vecXMLTags[pos2];
	    m_vecXMLTags[pos2] = p;
	}
}


