#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>
#include <fstream>
#include <iostream>

class CLogger
{
	std::ofstream log;

public:

	CLogger( std::string filename )
	{
		log.open( "logs/" + filename );
	}

	~CLogger( void )
	{
		log.close();
	}

	void Write( std::string str )
	{
		log << str << std::endl;
		std::cout << str << std::endl;
	}


};

#endif /* __LOGGER_H__ */