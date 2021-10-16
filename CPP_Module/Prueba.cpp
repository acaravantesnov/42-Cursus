/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prueba.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 03:19:53 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/14 03:30:52 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
using namespace std;

class Persona
{
	private:
		int edad;
		string nombre;
	public:
		Persona(int, string);
		void leer();
		void correr();
};

Persona::Persona(int _edad, string _nombre)
{
	edad = _edad;
	nombre = _nombre;
}

void	Persona::leer()
{
	cout << "Soy " << nombre << " y estoy leyendo un libro." << endl;
}

void	Persona::correr()
{
	cout << "Soy " << nombre << " y estoy corriendo una marathon." << endl;
}

int	main(void)
{
	Persona p1 = Persona(20, "Alejandro");
	p1.leer();
	return (0);
}