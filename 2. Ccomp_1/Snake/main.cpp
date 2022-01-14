#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

class Punto2D{
public:
    int x, y;
};
class Gusano{
public:
    Punto2D posicion;
    Punto2D choque;
    char *nombre;
    bool choque_limite = false;
    bool choque_gusano = false;
};
void estado(Gusano gusano1, Gusano gusano2){ //Funcion de impresion de las coordenadas de las instancias
    if (gusano1.choque_limite){
    cout<<"\nPosicion del "<<gusano1.nombre<<" ("<<gusano1.posicion.x<<","<<gusano1.posicion.y<<") choco\n";
    }
    else{
        cout<<"\nPosicion del "<<gusano1.nombre<<" ("<<gusano1.posicion.x<<","<<gusano1.posicion.y<<")\n";
    }
    if (gusano2.choque_limite){
        cout<<"\nPosicion del "<<gusano2.nombre<<" ("<<gusano2.posicion.x<<","<<gusano2.posicion.y<<") choco\n";
    }
    else{
        cout<<"\nPosicion del "<<gusano2.nombre<<" ("<<gusano2.posicion.x<<","<<gusano2.posicion.y<<")\n";
    }
    if (gusano1.choque_gusano){
        cout<<"\nGusano 1 y Gusano 2 chocaron en ("<<gusano1.choque.x<<","<<gusano1.choque.y<<")"<<endl;
    }
}
class Tablero{
public:
    char tecla[10];
    int anterior_posicion_x1, anterior_posicion_y1, anterior_posicion_x2, anterior_posicion_y2, choques = 0;
    char matriz[8][8], colision[8][8];
    void posicion_anterior(Gusano gusanito, int &anterior_posicion_x, int &anterior_posicion_y){ //Funci�n que permite guardar la anterior posici�n en caso de que una instancia choque con un lugar donde ya anteriormente ha chocado
        anterior_posicion_x=gusanito.posicion.x;
        anterior_posicion_y=gusanito.posicion.y;
    }
    void actualizar(Gusano &gusanito, Gusano &villano, bool &endwhile){ //Funci�n que recibe las instancias para calcular su movimiento respectivo
        cin>>tecla;
        posicion_anterior(gusanito,anterior_posicion_x1,anterior_posicion_y1);
        posicion_anterior(villano,anterior_posicion_x2,anterior_posicion_y2);
        if(strcmp(tecla,"w")==0){
            gusanito.posicion.y-=1;
        }
        if(strcmp(tecla,"a")==0){
            gusanito.posicion.x-=1;
        }
        if(strcmp(tecla,"s")==0){
            gusanito.posicion.y+=1;
        }
        if(strcmp(tecla,"d")==0){
            gusanito.posicion.x+=1;
        }
        if(strcmp(tecla,"i")==0){
            villano.posicion.y-=1;
        }
        if(strcmp(tecla,"j")==0){
            villano.posicion.x-=1;
        }
        if(strcmp(tecla,"k")==0){
            villano.posicion.y+=1;
        }
        if(strcmp(tecla,"l")==0){
            villano.posicion.x+=1;
        }
        if(strcmp(tecla, "q")==0 || strcmp(tecla,"Q")==0){
            endwhile = false;
        }
    }
    void limites(Gusano &gusanito){ // Funci�n para retroceder a la instancia en caso de que haya colisionado con un limite
        gusanito.choque_limite = false;
        if(gusanito.posicion.x<0){
            gusanito.posicion.x+=1;
            gusanito.choque_limite = true;
        }
        if(gusanito.posicion.y<0){
            gusanito.posicion.y+=1;
            gusanito.choque_limite = true;
        }
        if(gusanito.posicion.y>7){
            gusanito.posicion.y-=1;
            gusanito.choque_limite = true;
        }
        if(gusanito.posicion.x>7){
            gusanito.posicion.x-=1;
            gusanito.choque_limite = true;
        }
    }
    void colisionAccidente1(Gusano &gusanito){ //Funci�n para evitar que la instancia ingrese a la posici�n donde colision� anteriormente
        if(colision[gusanito.posicion.y][gusanito.posicion.x]=='#'){
            gusanito.posicion.x = anterior_posicion_x1;
            gusanito.posicion.y = anterior_posicion_y1;
        }
    }
    void colisionAccidente2(Gusano &villano){ //Funci�n para evitar que la instancia ingrese a la posici�n donde colision� anteriormente
        if(colision[villano.posicion.y][villano.posicion.x]=='#'){
            villano.posicion.x = anterior_posicion_x2;
            villano.posicion.y = anterior_posicion_y2;
        }
    }
    //Se creo dos funciones puesto que las variables utilizadas guardan diferentes valores de las coordenadas de los gusanos
    void colisionGusanos(Gusano &gusanito, Gusano &villano,bool &endgame ,int &choques){ // Funci�n que indica la colisi�n de las instancias reescribiendo las coordenadas de las dos
        gusanito.choque_gusano = false;
        bool endwhile= true;
        if(gusanito.posicion.x == villano.posicion.x){ //Almecenamos la colisi�n en otra matriz
            if(gusanito.posicion.y==villano.posicion.y){
                choques+=1;
                if(choques==5){
                    endgame = false;
                }
                gusanito.choque.x= gusanito.posicion.x;
                gusanito.choque.y= gusanito.posicion.y;
                colision[gusanito.posicion.y][gusanito.posicion.x]='#';
                while (endwhile){
                    srand(time(0));
                    gusanito.posicion.x=rand() %7;
                    gusanito.posicion.y=rand() &7;
                    villano.posicion.x =rand() %7;
                    villano.posicion.y =rand() %7;
                    if((colision[gusanito.posicion.y][gusanito.posicion.x]!='#') && (colision[villano.posicion.y][villano.posicion.x]!='#')){
                        gusanito.choque_gusano = true;
                        endwhile=false;
                    }
                }
            }
        }
    }
    void dibujar(Gusano &gusanito, Gusano &villano,bool &endgame){//Funci�n principal
        colisionAccidente1(gusanito);
        colisionAccidente2(villano);
        limites(gusanito);
        limites(villano);
        colisionGusanos(gusanito,villano,endgame,choques);
        for (int i=0; i<8;i++){
            for (int j=0;j<8;j++){
                matriz[i][j]='_';
                if(gusanito.posicion.y==i){
                    if(gusanito.posicion.x==j){
                        matriz[i][j]='@';
                    }
                }
                if(villano.posicion.y==i){
                    if(villano.posicion.x==j){
                        matriz[i][j]='0';
                    }
                }
                if(colision[i][j]== '#'){
                    matriz[i][j]=colision[i][j];
                }
                if(j==0){
                    cout<<"|"<<matriz[i][j]<<"|";
                }
                else{
                    cout<<matriz[i][j]<<"|";
                }
            }
            cout<<endl;
        }
    }
};
void iniciar_gusano(Gusano &gusanito, int x, int y, char* nombre){ //Funci�n para inicializar las instancias
    gusanito.posicion.x=x;
    gusanito.posicion.y=y;
    gusanito.nombre= nombre;
}
int main()
{
    bool endgame = true;
    Tablero cuadro;
    Gusano gusano1;
    iniciar_gusano(gusano1, 0, 0, "Gusano 1");
    Gusano gusano2;
    iniciar_gusano(gusano2, 7, 7, "Gusano 2");
    cuadro.dibujar(gusano1,gusano2,endgame);
    do{
        cuadro.actualizar(gusano1,gusano2,endgame);
        system("cls");
        cuadro.dibujar(gusano1,gusano2,endgame);
        estado(gusano1,gusano2);
    }while(endgame);
    return 0;
}
