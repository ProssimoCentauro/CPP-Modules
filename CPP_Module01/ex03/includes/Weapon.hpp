#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon( const std::string& type );
		Weapon( );
		~Weapon( );

		void setType(const std::string& type );
		const std::string&	getType( void ) const;
};

#endif
