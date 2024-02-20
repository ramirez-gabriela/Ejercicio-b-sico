/*Crea una clase llamada animal. Crea una app que permita alimentar un perro, 
un gato, un pez, que permita ponerlos a dormir, despertar, jugar,comer*/

#include<iostream>
#include <string>
#include <vector>
#include<stdlib.h>

using namespace std;
// Clase padre
class Animal{
	protected:
		bool estado;    // 1->Despierto  0->Dormido
	public:
		Animal(string,bool);       // Constructor
		virtual ~Animal();		   // Destructor
		
		string nombre;  // Variable para guardar el nombre de la mascota
		
		void alimentar();   
		void dormir();
		void despertar();
		virtual void jugar();
		virtual void mostrar();
};

// Constructor
Animal::Animal(string _nombre, bool _estado){
	nombre= _nombre;
	estado= _estado;
};

// Destructor
Animal::~Animal(){};

void Animal::mostrar(){
	cout<<nombre<<endl;
};

void Animal::alimentar(){
	if(estado!=0){  // Está despierto
		cout<<nombre<<" ha sido alimentado.\n";
	}else{
		cout<<"Primero despierta al animal para alimentarlo.\n";
	}
	system("pause");
	system("cls");
};

void Animal::dormir(){
	if(estado==1){ // Comprobar que esté despierto para que vaya a dormir
		estado=0;
		cout<<nombre<<" ha ido a dormir.\n";
	}else{
		cout<<nombre<<" ya está durmiendo.\n";
	}
	system("pause");
	system("cls");
};

void Animal::despertar(){ // Comprobar que esté dormido para despertarlo
	if(estado==0){
		estado=1;
		cout<<nombre<<" está despierto.\n";
	}else{
		cout<<nombre<<" ya está despierto.\n";
	}
	system("pause");
	system("cls");	
};

void Animal::jugar(){};
// Clases derivadas
class Perro : public Animal{
	private:
		string tipo;	
	public:
		Perro(string,bool,string);   // Constructor
		void mostrar();
		void jugar();
};

class Gato : public Animal{
	private:
		string tipo;	
	public:
		Gato(string,bool,string);
		void mostrar();
		void jugar();
};

class Pez : public Animal{
	private:
		string tipo;	
	public:
		Pez(string,bool,string);
		void mostrar();
		void jugar();
};

Perro::Perro(string _nombre,bool _estado,string _tipo): Animal(_nombre,_estado){
	tipo= _tipo;
};

Gato::Gato(string _nombre,bool _estado,string _tipo): Animal(_nombre,_estado){
	tipo= _tipo;
};

Pez::Pez(string _nombre,bool _estado,string _tipo): Animal(_nombre,_estado){
	tipo= _tipo;
};

void Perro::mostrar(){
	Animal::mostrar();
};

void Gato::mostrar(){
	Animal::mostrar();
};

void Pez::mostrar(){
	Animal::mostrar();
};

void Perro::jugar(){
	int juego;
	if(estado==1){
		cout<<"-------------------------\n";
		cout<<"Opciones para jugar con el perro:\n\n";
		cout<<"1. A la pelota.\n";
		cout<<"2. Correr.\n";
		cout<<"3. Lanzar y recoger el palo.\n";
		cout<<"\nOpción: ";
		cin>>juego;
		
		cout<<"\n";
		if(juego==1){
			cout<<"Jugando a la pelota con "<<nombre<<endl;
		}else if(juego==2){
			cout<<"Ir a correr con "<<nombre<<endl;
		}else if(juego==3){
			cout<<"Jugando a lanzar el palo y que "<<nombre<<" lo recoja."<<endl;
		}else{
			cout<<"Upss, opción inválida."<<endl;
		}
	}else{
		cout<<"Primero despierta a "<<nombre<<" para que pueda jugar.\n";
	}
	system("pause");
	system("cls");
};

void Gato::jugar(){
	int juego;
	if(estado){
		cout<<"-------------------------\n";
		cout<<"Opciones para jugar con el gato:\n\n";
		cout<<"1. Juego de caza o cebo.\n";
		cout<<"2. Perseguir luz.\n";
		cout<<"3. Lanzar y recoger al ratón de juguete.\n";
		cout<<"\nOpción: ";
		cin>>juego;
		
		cout<<"\n";
		if(juego==1){
			cout<<nombre<<" está persiguiendo el cebo.\n"<<endl;
		}else if(juego==2){
			cout<<"Jugar a que "<<nombre<<" persiga la luz.\n"<<endl;
		}else if(juego==3){
			cout<<"Jugando a lanzar al ratón de juguete y que "<<nombre<<" lo recoja."<<endl;
		}else{
			cout<<"Upss, opción inválida."<<endl;
		}
	}else{
		cout<<"Primero despierta a "<<nombre<<" para que pueda jugar.\n";
	}
	system("pause");
	system("cls");
};

void Pez::jugar(){
	if(estado){
		cout<<"Llamar la atención de "<<nombre<<" para que siga un objeto.\n";
	}else{
		cout<<"Primero despierta a "<<nombre<<" para que pueda jugar.\n";
	}
	system("pause");
	system("cls");
};

int main(){
	setlocale(LC_ALL, "spanish");
	// Número de animales a registrar ->num
	int num,tipo,opcion_menu,n;
	string nombre_animal;
	// El primer booleano es para confirmar que el valor de animales a registrar sea válido
	bool est=false,continuar=true;
	
	cout<<"\t\tMenú para cuidar animales\n";
	cout<<"\t\t-------------------------\n\n";
	cout<<"Registo de animales.\n"<<endl;	
			
	do{ // Condición para registrar un número válido de animales
		cout<<"Cuántos animales quiere registrar: ";
		cin>>num;
		if(num<=0){
			cout<<"El valor ingresado no es válido. Intente nuevamente.\n";
			est=false;
		}else{
			est=true;
		}
	}while (!est);
	
	vector<Animal*> animales;
	
	for(int i=0;i<num;i++){
		cout<<"\nNombre: ";
		cin>>nombre_animal;
		
		cout<<"Ingrese el número correspondiente al tipo de animal: "<<endl;
		cout<<"1. Perro\n2. Gato\n3. Pez\n"<<endl;
		cout<<"Opción: ";
		cin>>tipo;
		
		// Por defecto, los animales se registran despiertos (1)
		switch(tipo){
			case 1:
				animales.push_back(new Perro(nombre_animal,1,"Perro"));
				break;
			case 2:
				animales.push_back(new Gato(nombre_animal,1,"Gato"));
				break;
			case 3:
				animales.push_back(new Pez(nombre_animal,1,"Pez"));
				break;
			default:
				cout<<"Opción inválida.\n";
				break;
		}
	}
	system("pause");
	
	// Menú para métodos de clases
	while(continuar){
		system("cls");
		cout<<"\t\tMenú de actividades\n";
		cout<<"\t\t-------------------\n";
		cout<<"Elija su animal:\n";
		for(int i=0;i<num;i++){
			cout<<"\t"<<i+1<<". ";
			animales[i]->mostrar();
		}
		
		bool estado_sec;
		do{
			cout<<"\nOpción: ";
			cin>>n;n--;
			
			if(n>=0 && n<num){
				estado_sec=false;
			}else{
				cout<<"Opción inválida. Intente nuevamente.\n\n";
				estado_sec=true;
			}
		}while(estado_sec);
		
		cout<<"\n-------------------------\n";
		cout<<"Elije la actividad para ";
		animales[n]->mostrar();
		
		cout<<"1. Alimentar\n";
		cout<<"2. Jugar\n";
		cout<<"3. Despertar\n";
		cout<<"4. Descansar o dormir\n";
		cout<<"5. Finalizar programa\n";
		cout<<"\nOpción: ";
		cin>>opcion_menu;
		
		cout<<endl;
		switch(opcion_menu){
			case 1:
				animales[n]->alimentar();
				break;
			case 2:
				animales[n]->jugar();
				break;
			case 3:
				animales[n]->despertar();
				break;
			case 4:
				animales[n]->dormir();
				break;
			case 5:
				cout<<"Fin de la ejecución. Hasta pronto.\n";
				continuar=false;
				break;
			default:
				cout<<"La opción ingresada no es válida. Intente nuevamente.\n";
				break;
		}	
	}
	
	for(int i=0; i<num; i++) {
        delete animales[i];
        cout<<"\nEliminando...";
    }
    
	return 0;
}

