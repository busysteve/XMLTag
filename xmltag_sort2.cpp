#include <iostream>
#include "xmltag.h"


int main( int argc, const char **argv )
{
    XMLTag xml("bookstore");
    XMLTag &books = xml.addTag("books");

    XMLTag &book1 = books.addTag("book");
    book1.addTag( "title", "Visual Basic .NET" );
    book1.addTag( "price", "48.95" );

    XMLTag &book2 = books.addTag("book");
    book2.addTag( "title", "Grilling" );
    book2.addTag( "price", "45.75" );

    XMLTag &book3 = books.addTag("book");
    book3.addTag( "title", "jQuery" );
    book3.addTag( "price", "52.99" );

    XMLTag &book4 = books.addTag("book");
    book4.addTag( "title", "Cooking Eggs" );
    book4.addTag( "price", "12.95" );

    XMLTag &book5 = books.addTag("book");
    book5.addTag( "title", "C++ Programming Language" );
    book5.addTag( "price", "52.95" );

    XMLTag &book6 = books.addTag("book");
    book6.addTag( "title", "Ajax Programming" );
    book6.addTag( "price", "39.95" );
    
    // Print tab formatted XML output
    std::cout << std::endl << xml.getXMLFormatted() << std::endl;

    try
    {
    	books.sortAlpha("title");
    }
    catch( XMLTagException &e )
    {
	std::cout << e.msg << " " << e.sample << std::endl;
    }  
    // Print tab formatted XML output
    std::cout << std::endl << xml.getXMLFormatted() << std::endl;

    try
    {
    	books.sortFloat("price");
    }
    catch( XMLTagException &e )
    {
	std::cout << e.msg << " " << e.sample << std::endl;
    }  
    // Print tab formatted XML output
    std::cout << std::endl << xml.getXMLFormatted() << std::endl;
}
