#include <iostream>
#include <string>
using namespace std;

class Persona{
  protected:
    string nombre;
    int edad;
  public:       
    Persona(string,int); //constructor
    ~Persona(); //destructor
    virtual void mostrar(); //función de polimorfismo va en la clase padre
};

Persona::Persona(string _nombre, int _edad){
    nombre=_nombre;
    edad=_edad;
};

Persona::~Persona(){ };

void Persona::mostrar(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
};

class Alumno : public Persona{
    private:
        float notaFinal;
    public:
        Alumno (string,int,float); //constructor de Alumno
        void mostrar();
        float getNotaFinal() const { return notaFinal; }
};

Alumno::Alumno(string _nombre,int _edad, float _notaFinal) : Persona (_nombre,_edad){
    notaFinal=_notaFinal;
};

void Alumno :: mostrar(){
    Persona::mostrar();
    cout<<"Nota Final: "<<notaFinal<<endl;
};

class Profesor : public Persona{
	private:
		string asignatura;   // Atributo único del profesor
	public:
		Profesor (string,int,string);	// Constructor
		void mostrar(); 
};

// Objeto
Profesor::Profesor(string _nombre,int _edad, string _asignatura) : Persona (_nombre,_edad){
	asignatura=_asignatura;
};

void Profesor::mostrar(){
	Persona::mostrar();
	cout<<"Asignatura: "<<asignatura<<endl;
}

int main(){
	setlocale(LC_ALL, "spanish"); 
	Persona *lista[3];
	lista[0]=new Profesor("Juan",28,"Lógica");  //Objetos
	lista[1] = new Alumno("Jose",19,4.9);
    lista[2] = new Alumno("Maria",17,4.5);
    
    for(int i=0;i<3;i++){
        (*lista[i]).mostrar(); // lista[i]->mostrar();
        cout<<endl;
    }
    
    // Crear una lista 2 para estudiantes y profesores de una materia: Programación
    // Mostrar a los alumnos que perdieron con una nota inferior a 3
    
    Persona *lista1[5];
    lista1[0]=new Profesor("Jorge",32,"Programación");  //Objetos
	lista1[1] = new Alumno("Jose",19,2.9);
    lista1[2] = new Alumno("Maria",17,4.0);  
	lista1[3] = new Alumno("Luís",20,4.3);
    lista1[4] = new Alumno("Anita",17,2.5);
    
    cout<<"\nAlumnos que no aprobaron"<<endl<<endl;
    cout<<"Asignatura: Programación"<<endl;
    for(int i=1;i<5;i++){
    	Alumno *alumno = dynamic_cast<Alumno *>(lista1[i]);
    	if((alumno != nullptr) && (alumno->getNotaFinal() < 3)){
    		(*lista1[i]).mostrar();
    		//cout<<"Nota final: "<<alumno->getNotaFinal()<<endl;
    		cout<<endl;
		}
	}
	
	// Liberar memoria
    for (int i = 0; i < 3; i++) {
        delete lista[i];
    }
    
    for (int i = 0; i < 5; i++) {
        delete lista1[i];
    }	
    
    return 0;
}
