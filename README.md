XMLTag: A simple XML wrapper class for reading and writing XML for C++
======================================================================
- [Intro](#intro)
- [User Guide](#user-guide)
    - [Public Member Functions](#public-member-functions)
    - [Constructor & Destructor Documentation](#constructors-&-destructors)
    - [Member Function Documentation](#member-function-documentation)
- [License](#license)

Intro
-----
XMLTag is an awesome XML class that handles parsing XML.

User Guide
----------

Public Member Functions
-----------------------

Constructor & Destructor Documentation
--------------------------------------
```c++
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
```

Member Function Documentation
-----------------------------

License
-------
This software is licensed under the [GPL v2 license][gpl].
© 1999 Stephen D. Mathews Jr. 

[gpl]: http://www.gnu.org/licenses/old-licenses/lgpl-2.1-standalone.html
