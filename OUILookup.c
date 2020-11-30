
//Nicolas Mora 19343663-3




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Declaramos las variables Globales que nos piden

/* Aqui declararemos las 2 variables que debemos usar de forma global, 
para trabajarlas en forma de comparacion con el archivo que incluye la informacion 
y una variable para guardar el nombre con el que se conoce la ip de forma coloquial y el de comando qye ingresa el usuario*/
char ip[15]; 
char mac[15];
char nombre[30]; 
char Comando[99]; //esta variable se encargara de saber que comando es el q se utilizara por el usuario
int aux;

//aqui declararemos las funciones que generamos en el programa, utilizaremos funciones para que quede mas ordenado cada proceso.
void Presentacion();
void Comandos();
void Comandoip();
void Comandomac();
void Comandohelp();
void Leer();


//Funcion principal para q el programa funcione
int main(void){
    // Your code here!
    
    printf("\n Bienvenido \n \n ");
     Presentacion();
     
     aux = 1; 
     while(aux==1){
         Leer();
         Comandos();
         switch(aux){
            case 1: //--ip
                Comandoip();
                break;
         case 2:        //--mac      
                Comandomac();
             break;
         case 3://   --help
             Comandohelp();
             break;
          case 4: //--ip I --mac --help
              Comandoip();
                Comandomac();
                Comandohelp();
               break;
       }
          aux=1;
          printf("\n \n Quieres hacer otra busqueda: 1 para si, 2 para no, por defecto cerrara el programa al introducir otro caracter\n \n ");   
            switch(aux){
                case 1:
                    break;
                case 2:
                    aux=0;
                    break;
                default:
                    aux = 0; 
                    break;
            }
          
     }

    return 0; 
}


//Funciones del programa

//Funcion para presentar el uso del programa y sus comandos correspondiente
void Presentacion(){
    
    printf("\n \n Este programa usa los siguientes comandos: \n --ip \n --mac \n --help\n --ip <IP> | --mac <IP>. --help \n Donde en este ultimo comando debe reemplazar incluyendo <> para su busqueda \n \n  ");
}



//Esta funcion esta encarga de diferenciar que comando es el q utiliza el usuario
void Comandos(){
    
    /*leemos que comando ingreso el uruario y verificamos q no sea otro comando extraño o error de tipeo del usuario
    
    */
    //no podemos usar swtich para cadenas de caracteres en c, usamos uan serie de if y else
    int i=0;
    while(i==0){
         if (strcmp(Comando, "--ip") == 0) { //equivalen a aux=1
        //si El comando del usuario es --ip entonces seguimos con lo solicitado para la ip
            aux=1;
          i++;
        
        }else {
        
            if(strcmp(Comando, "--mac") == 0) { //equivalente a aux=2
               //si El comando del usuario es --mac entonces seguimos con lo solicitado para la mac
                aux=2;
               i++;
              
           }else{
               
               if(strcmp(Comando, "--help") == 0){ //equivalente a aux=3
                    //si El comando del usuario es --help entonces seguimos con lo solicitado para la help
                     aux=3;
                    i++;
                      
               }else{
                     if(strcmp(Comando, "--ip <IP> | --mac <IP>. --help") == 0){ //equivalente a aux=4
                   
                   //si El comando del usuario es --mac entonces seguimos con lo solicitado para la mac
                       aux=4;
                        i++;
                    }else{  
                    
                    printf ("\n \n Comando Invalido \n Ingrese un comando valido: \n  --ip \n --mac \n --help \n--ip <IP> | --mac <IP>. --help \n \n ");
                    }
               }
            }
        }
    }
    
}



/*Esta funcion se escargara de realizar las tareas correspondientes al momento de 
tomar la eleccion del comando --ip, el cual lo guardara en una variable y comparara con el archivo
*/
void Comandoip(){
    //leemos la mac a buscar
    gets(ip);
    //buscar la mac y guardar el nombre q representa en la variable nombre
    FILE* fichero;
    fichero = fopen("manuf.txt", "rt");
    char linea="";
    while ((linea= br.readLine())!=null) {
                
                if(linea.equalsIgnoreCase(ip[])) {

                    for(int i=0;i<2;i++) {
                        nombre[]=br.readLine();
                    }   
                    break;

                }else {
                    printf("La mac introducido no existe.");

                    break;
                }
    }
}



//Esta funcion se escargara de realizar las tareas correspondientes al momento de 
//tomar la eleccion del comando --mac
void Comandomac(){
    //leemos la mac a buscar
    gets(mac);
    //buscar la mac y guardar el nombre q representa en la variable nombre
    FILE* fichero;
    fichero = fopen("manuf.txt", "rt");
    char linea="";
    while ((linea= br.readLine())!=null) {
                
                if(linea.equalsIgnoreCase(mac[])) {

                    for(int i=0;i<2;i++) {
                        nombre[]=br.readLine();
                    }   
                    break;

                }else {
                    printf("La mac introducido no existe.");

                    break;
                }
    }
    
}



//Esta funcion se escargara de realizar las tareas correspondientes al momento de 
//tomar la eleccion del comando --help el q sera utilizado para mostrar por pantalla las variables globales solicitadas
void Comandohelp(){
    printf ("\n \n ip: %s \n mac: %s \n Nombre: %s", &ip, &mac, &nombre );
    
    
}


//Funcion para leer el comando que ingresa el usuariocom

void Leer(){
    gets(Comando);
    
}