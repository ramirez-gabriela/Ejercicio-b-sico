import math

class Persona:
    def __init__ (self,nombre,edad):
        self.nombre=nombre
        self.edad=edad
        
    def mostrar(self):
        print ("Nombre", self.nombre)
        print ("Edad", self.edad)
        
class Alumno (Persona) :
    def __init__ (self, nombre,edad,notaFinal):
        super().__init__(nombre,edad)
        self.notaFinal=notaFinal
    
    def mostrar(self):
        super().mostrar()
        print ("Nota Final: ", self.notaFinal)
        
class Profesor (Persona) :
    def __init__ (self, nombre,edad,materia):
        super().__init__(nombre,edad)
        self.materia=materia
    
    def mostrar(self):
        super.mostrar()
        print ("Materia: ", self.materia) 

if __name__ == '__main__':
    promedio,cont=0,0
    
    lista1 = [
        Profesor ("Maria", 30, "Logica"),
        Alumno ("Juan", 19, 4.2),
        Alumno ("Jose", 20, 4.5),
        Alumno ("Miguel", 21, 2.2)
        ]
        
    for p in lista1:
        if isinstance(p,Alumno):
            promedio+=p.notaFinal;
            cont+=1
            
        if isinstance (p, Alumno) and p.notaFinal<3:
            p.mostrar()
        
    promedio=promedio/cont
    print("\nEl promedio de clase es: ",round(promedio,2))