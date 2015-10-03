#include <iostream>
#include "xmltag.h"


int main( int argc, const char **argv )
{
    XMLTag xml("toptag");
    XMLTag &ref = xml.addTag("innertag");
    ref.addTag("child1", "sammy");
    ref.addTag("child3", "frank"); // Will not be sorted : retains inserted order
    ref.addTag("child2", "tootie");
    
    // Print third child of inner tag
    std::cout << xml["innertag"][2].value() << std::endl;
    
    // Print tab formatted XML output
    std::cout << std::endl << xml.getXMLFormatted() << std::endl;
}
