#pragma once
#include <assert.h>
#include <iostream>
using namespace std;

namespace Geom {
	template<class T>
	class Vecteur3D
	{
	public:
		Vecteur3D(T x = 0.0, T y = 0.0, T z = 0.0);
		Vecteur3D(const Vecteur3D<T>&) = delete;//on a interdire l'utilisation de constructeur
											 //par d�faut et aussi notre constructeur
		//op�rteur d'affectation
		Vecteur3D& operator= (const Vecteur3D<T>&) = delete;//la meme chose
		void print() const;//afficher le vecteur 
		T at(T) const;//la valeur de chaque indice
		bool operator==(const Vecteur3D<T>& v) const; //la 1er const porteger le 2eme objet de comparaison
												  // 2eme const proteger le 1er objet
		bool operator!=(const Vecteur3D<T>& v) const;
		T& operator[](T);
		//friend void display(Vecteur3D& v);//il donne acc�es au m�thode afficher
										  //-5pt EXAM
		void display(Vecteur3D<T>& v);
	private:
		T vect[3];


	};
	//template<class T>
	//void Vecteur3D<T> display(Vecteur3D& v);
	template<class T>

	Vecteur3D<T>::Vecteur3D(T x, T y, T z)
	{
		this->vect[0] = x;
		this->vect[1] = y;
		this->vect[2] = z;

	}
	template<class T>
	void  Geom::Vecteur3D<T>::print() const
	{
		for (int i = 0; i < 3; i++)

		{
			cout << "vecteur[" << i << "]=" << this->at(i) << endl;
		}
	}
	template<class T>
	T  Geom::Vecteur3D<T>::at(T i) const
	{
		assert(i >= 0 && i < 3); //debug

		try { //releas
			if (i < 0 || i >= 3) throw "rang erre";
			return this->vect[i];
		}
		catch (char* e)
		{
			cout << e << endl;
		}

		return 0.0f;
	}
	template<class T>
	bool  Geom::Vecteur3D<T>::operator==(const Vecteur3D<T>& v) const
	{
		bool res = true;
		for (int i = 0; i < 3; i++)
		{
			res = res && (this->at(i) == v.at(i));//impossible d'appeler une methode const a interieur d'une autre non const
		}
		return false;
	}
	template<class T>
	bool  Geom::Vecteur3D<T>::operator!=(const Vecteur3D<T>& v) const
	{
		bool res = !(*this == v);//retourner inverse de resultat de ==

		return false;
	}
	template<class T>
	T& Geom::Vecteur3D<T>::operator[](T i)
	{

		assert(i >= 0 && i < 3); //debug

		try { //releas
			if (i < 0 || i >= 3) throw "rang erre";
			return this->vect[i];
		}
		catch (char* e)
		{
			cout << e << endl;
		}

		//return 0.0f;

	}

	template<class T>
	void Geom::Vecteur3D<T>::display(Vecteur3D<T>& v)
	{
		for (int i = 0; i < 3; i++)

		{
			cout << "vecteur[" << i << "]=" << v.at(i) << endl; //on utilise vect(i) si on utilise la classe friend
		}
	}


};











/***************NOTE DE COURS********************
* comment utiliser les donn�e des classe sans passer par get &set et frient:
  communiquer via a l'aide des services
  ce qui nous oblige de d�clarer des m�thodes
  public dans la classe o� se trouve les donn�es

*  OBJECTIF*********** garder la maintenence des projets****************


****************la penalit� dans les �valuations c'est l'optimalit� des codes************************OOP avec les bons pratique**********/
