/**
@file xml/EmptyElement.cpp
Ce fichier contient la réalisation de la classe EmptyElement.
@author Benjamin PLANCHE, Benjamin BOUVIER
*/

# include "EmptyElement.hpp"
# include <functional>
# include <algorithm>
using namespace std;

namespace xml
{
	/**
	@brief Foncteur pour la recherche par nom d'attribut via std::find.
	*/
	struct AttributName: public std::binary_function< Attribut, string, bool > {
		// Adaptable binary predicate to find an attribute using its name :
		bool operator () ( const Attribut &att, const string &name ) const {
			return att.first == name;
		}
	};

	string EmptyElement::endCharacter()
	{
		return "/>";
	}

	string EmptyElement::beginCharacter()
	{
		return "<";
	}

	string EmptyElement::getName()
	{
		return name.second;
	}

	string EmptyElement::getNamespace()
	{
		return name.first;
	}

	string EmptyElement::getFullName()
	{
		return (name.first != "" ? name.first + ":" : "") + name.second;
	}

	string EmptyElement::getAttributeValue(string attributeName)
	{
		string value;
		list<Attribut>::iterator attr = attributes.begin();
		attr = find_if( attr, attributes.end(), bind2nd( AttributName(), attributeName ) );
		if (attr != attributes.end()) { value = attr->second; }
		return value;
	}

	void EmptyElement::addAttribute(Attribut attr) {
		attributes.push_back(attr);
	}

	ostream& EmptyElement::toString(ostream& stream, int depth)
	/*
	On affiche d'abord la balise ouvrante, l'ensemble des attributs puis la balise
	fermante.
	*/
	{
		printTabs(stream, depth);
		stream << beginCharacter(); 
		if (!name.first.empty())
		{
			stream << name.first << ":";
		}

		stream << name.second;
		for(AttList::iterator it = attributes.begin();
			it != attributes.end();
			++it)
		{
			stream << " " << it->first << "=\"" << it->second << "\"";
		}
		stream << endCharacter(); 
		return stream;
	}
}
