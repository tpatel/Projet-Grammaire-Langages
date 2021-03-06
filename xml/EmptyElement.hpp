#ifndef __XML_EMPTY_ELEMENT_H__
#define __XML_EMPTY_ELEMENT_H__

/**
@file xml/EmptyElement.hpp
Ce fichier contient l'entête de la classe EmptyElement.
@author Benjamin BOUVIER
*/

# include "Content.hpp"
# include "basics.h"

# include <string>
namespace xml {

	/**
	@brief Balise non contenante en xml

	Cette classe modélise un élément (balise) non contenant.
	*/
	class EmptyElement : public Content 
	{
	protected:
		/**
		Liste des attributs (pair<nom, valeur>) de l'élément
		courant.
		*/
		AttList attributes;

		/**
		Nom de l'élément en cours (pair<namespace, nom>).
		*/
		ElementName name;	

		/**
		Représente le dernier caractère à afficher quand toString est
		appelé. Pour EmptyElement, il s'agit de "/>" alors que c'est ">"
		pour Element.
		@returns "/>"
		*/	
		virtual std::string endCharacter(); 

		/**
		Représente l'élément initial à afficher quand toString est appelé.
		@returns "<"
		*/
		virtual std::string beginCharacter();
	public:
		/**
		Constructeur par défaut.
		*/
		EmptyElement() 
		{
		/* empty */
		}
		
		/**
		Destructeur vide (pour pouvoir détruire les objets des classes filles).
		*/
		virtual ~EmptyElement() {}

		/**
		Mutateur : donne le nom _n à l'élément courant.
		@param _n Nom de l'élément : pair<namespace, nom>
		*/
		void setName(ElementName _n) { name = _n; }

		/**
		Mutateur : attribue la liste d'attributs à l'élément courant.
		@param _l Liste d'attributs (un attribut est de la forme pair<nom,
		valeur>).
		*/
		void setAttList(AttList _l) { attributes = _l; }
		/**
		Accesseur : renvoie la liste des attributs de l'élément courant.
		*/		
		AttList getAttList() { return attributes; }

		/**
		Mutateur : ajoute un attribut à la liste de ceux assignés à cet élément.
		@param attr Attribut à ajouter.
		*/
		void addAttribute(Attribut attr);
		/**
		Accesseur : renvoie le nom de l'élément courant.
		*/
		std::string getName();

		/**
		Accesseur : renvoie le namespace de l'élément courant.
		*/
		std::string getNamespace();

		/**
		Accesseur : renvoie le nom complet (avec namespace si présent) de l'élément courant.
		*/
		std::string getFullName();

		/**
		Accesseur : renvoie la valeur de l'attribut donné par le nom passé
		en paramètre.
		@param attributeName Nom de l'attribut dont on veut la valeur.
		@returns Valeur textuelle de l'attribut.
		*/
		std::string getAttributeValue(std::string attributeName);

		/**
		Affiche le contenu de l'élément courant dans le flux donné.
		@param stream Le flux dans lequel on écrit.
		@param depth La profondeur dans la hiérarchie xml.
		@returns Le flux dans lequel on a écrit.
		*/
		virtual std::ostream& toString(std::ostream& stream, int depth);
	};
}

#endif

