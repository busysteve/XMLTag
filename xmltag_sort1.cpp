#include <iostream>
#include "xmltag.h"


int main( int argc, const char **argv )
{
    XMLTag xml("toptag");
    XMLTag &ref = xml.addTag("innertag");
    ref.addTag("child", "3.8");
    ref.addTag("child", "9.335"); // Will not be sorted : retains inserted order
    ref.addTag("child", "22.432");
    ref.addTag("child", "2.432");
    ref.addTag("child", "1.432");
    
    // Print tab formatted XML output
    std::cout << std::endl << xml.getXMLFormatted() << std::endl;

    try
    {
    	ref.sortFloat("");
    }
    catch( XMLTagException &e )
    {
	std::cout << e.msg << " " << e.sample << std::endl;
    }  
    // Print tab formatted XML output
    std::cout << std::endl << xml.getXMLFormatted() << std::endl;
}
