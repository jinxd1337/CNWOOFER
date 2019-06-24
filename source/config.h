#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>
#include <map>

#include <tinyxml.h>

class CConfig
{
public:

	CConfig( std::string filename ) { ParseFile( filename );  }
	~CConfig( void ) {}

	std::string Filename;
	std::map<std::string, std::string> Params;

	std::string GetParamSz( std::string p )
	{
		return Params[ p ];
	}
	
	int GetParamI( std::string p )
	{
		return std::stoi( Params[ p ] );
	}
	
	void SetParam( std::string p, std::string v )
	{
		Params[ p ] = v;
	}

	bool ParseFile( std::string filename )
	{
		TiXmlDocument cfg;
		TiXmlElement *root, *ele;
		std::string var, param;

		Filename = filename;

		if( cfg.LoadFile( filename ) )
		{
			root = cfg.FirstChildElement();

			for( ele = root->FirstChildElement(); ele != NULL; ele = ele->NextSiblingElement() )
			{
				var = ele->ValueStr();
				param = ele->GetText();

				Params[ var ] = param;
			}

			return true;
		}

		return false;
	}
};


#endif /* __CONFIG_H__ */