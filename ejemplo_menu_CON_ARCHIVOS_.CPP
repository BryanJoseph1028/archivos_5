
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
   int  cuenta;
   char nomalum[40];
   float primpar;
   float segpar;
}  Alumno;

void  Crear(void);
void  Imprimir(void);
void  Anexar (void);
void  Modificar(void);
void  Borrar(void);

int op,cent;

main(){
      cent=6;
      while(cent<=6){
            printf("Bienvenido al menu de registro de alumnos, elige una opcion");
            printf("\n\n1.- Crear archivo y dar de alta a un alumno");
            printf("\n\n2.- Visualizar la lista existente");
            printf("\n\n3.- Anexar alumnos al archivo");
            printf("\n\n4.- Modificar el registro de un alumno");
            printf("\n\n5.- Borrar el registro de un alumno");
            printf("\n\n6.- Salir del menu");
            printf("\n\nOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  Crear();
               break;
               case 2:
                  Imprimir();
               break;
               case 3:
                  Anexar();
               break;
               case 4:
                  Modificar();
               break;
               case 5:
                  Borrar();
               break;
               case 6:
                  cent=7;
               break;
               default:
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        clrscr();
        }
        getch();
}

//Definicion de funciones//

//FUNCION PARA CREAR EL ARCHIVO//
void Crear(void){
   FILE *fp;
   Alumno alm;
   // Creacion del archivo y guardar datos
   if(!(fp=fopen("registro.alum","wb")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      clrscr();
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO Y DAR DE ALTA UN ALUMNO");
      printf("\n\nIntroduce el nombre del alumno: ");
      gets(alm.nomalum);
      printf("\nIntroduce el numero de cuenta del alumno");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce la calificacion del primer parcial:  ");
      scanf("%f",&alm.primpar);
      printf("\nIntroduce la calificacion del segundo parcial:  ");
      scanf("%f",&alm.segpar);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!REGISTRO REALIZADO CON EXITO!!!");
      printf("\nPresiona una tecl para continuar...");
      getch();
      fclose(fp);
   }
}

//FUNCION PARA IMPRIMIR EL REGISTRO DE ALUMNOS//
void Imprimir(void){
   FILE *fp;
   Alumno  alm;
   int n;
   if(!(fp=fopen("registro.alum","rb")))
   	printf("Error de apuertura del registro");
   else{
      clrscr();
      printf("\tELIGIO LA OPCION 2:IMPRIMIR REGISTRO DE ALUMNOS");
      printf("\n\n\t\t R E G I S T R O  D E  A L U M N OS\n");
      printf("\n------------------------------------------------------------------------------\n");
      printf("\tAlumno \t\t Cuenta \t Calif 1 \tCalif 2");
      printf("\n------------------------------------------------------------------------------\n");
      while ((n=fread(&alm, sizeof(alm),1, fp))!=0){
         printf("%s \t",alm.nomalum);
         printf("%d \t",alm.cuenta);
         printf("%2.2f\t\t",alm.primpar);
         printf("%2.2f\n",alm.segpar);
      }
      printf("\n------------------------------------------------------------------------------\n");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

//FUNCION PARA ANEXAR DATOS AL REGISTRO DE ALUMNOS//
void Anexar(void){
   FILE *fp;
   Alumno	alm;

   clrscr();
   printf("\tELIGIO LA OPCION 3: ANEXAR ALUMNOS AL ARCHIVO");
   printf("\n\n!!Se anexaran nuevos alumos al registro de alumnos!!\n");
   if(!(fp=fopen("registro.alum","ab")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      printf("\n\nIntroduce el nombre del alumno: ");
      gets(alm.nomalum);
      fflush(stdin);
      printf("\nIntroduce el numero de cuenta del alumno: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce la calificacion del primer parcial:  ");
      scanf("%f",&alm.primpar);
      printf("\nIntroduce la calificacion del segundo parcial:  ");
      scanf("%f",&alm.segpar);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!ANEXO REALIZADO CON EXITO!!!");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

//FUNCION PARA MODIFICAR UN REGISTRO CON BUSQUEDA
void Modificar(void){
   FILE *fp;
   Alumno alm;
   int n,c,opc;

   if(!(fp=fopen("registro.alum","r+b")))
   	printf("\n Error de apuertura del registro");
   else{
      clrscr();
      printf("\tELIGIO LA OPCION 4: MODIFICAR EL REGISTRO DE UN ALUMNO");
      printf("\n\nIntroduzca el numero de cuenta del alumno: ");
      scanf("%d",&alm.cuenta);
      c=alm.cuenta;
      while ((n=fread(&alm, sizeof(alm), 1, fp))!=0 && alm.cuenta!=c);
      if (alm.cuenta!=c)
         printf("No existe la Cuenta: %d ",c);
      else{
         clrscr();
         printf("\n!!Se encontro al alumno!!");
         printf("\n?Que desea cambiar?, Seleccione una opcion");
         printf("\n\n1.-Nombre");
         printf("\n\n2.-No. de cuenta");
         printf("\n\n3.-Calificacion del primer parcial");
         printf("\n\n4.-Calificacion del segundo parcial");
         printf("\n\nIntroduzca opicion: ");
         scanf("%d",&opc);
         switch(opc){
                     case 1:
                        fflush(stdin);
                        printf("\nIntroduzca el nuevo nombre: ");
                        gets(alm.nomalum);
                     break;
                     case 2:
                        printf("\nIntroduza el nuevo numero de cuenta: ");
                        scanf("%d",&alm.cuenta);
                     break;
                     case 3:
                        printf("\nIntroduzca la nueva calificacion del 1er parcial: ");
                        scanf("%f",&alm.primpar);
                     break;
                     case 4:
                        printf("\nIntrodizca la nueva calificacion del segundo parcial:  ");
                        scanf("%f",&alm.segpar);
                     break;
                     default:
                        printf("\Error, opcion inexistente");
                     break;
         }
         printf("\nGrabando registro\n");
         fseek(fp,-sizeof(alm),SEEK_CUR);
         fwrite(&alm, sizeof(alm), 1, fp);
         printf("\nRegistro grabado con exito");
         printf("\nPresiona una tecla para continuar...");
         getch();
      }
      fclose(fp);
   }
}

//FUNCION PARA BORRAR REGISTROS DE ALUMNOS//

void Borrar(void){
   FILE *fp,*fd;
   Alumno alm;
   int n,c,encontrado=0;
   clrscr();
   printf("\tELIGIO LA OPCION 5: BORRAR EL REGISTRO DE UN ALUMNO");
   printf("\n\nIngrese el numero de cuenta  del alumno para borrar el registro: ");
   scanf("%d",&alm.cuenta);
   c=alm.cuenta;
   if(!(fp=fopen("registro.alum","rb")))
   	printf("\n Error de apuertura del registro");
   else{
      if(!(fd=fopen("auxregis.txt","wb")))
         printf("\n Error,imposible borrar registro, el archivo no existe");
      else{
         while ((n=fread(&alm, sizeof(alm), 1, fp))!=0){
            if(alm.cuenta!=c)
              fwrite(&alm, sizeof(alm), 1, fd);
            else
              encontrado=1;
         }
         fclose(fd);
      }
      fclose(fp);
      if(encontrado){
         system("del registro.alum");
         system("ren auxregis.txt registro.alum");
         printf("\n!!!Registro borrado satisfactoriamente!!!\n");
         printf("\n\nPresiona una tecla para continuar");
         getch();
      }
      else{
         system("del auxregis.txt");
         printf("\n!!!No se entontro ningun alumno con ese numero de cuenta!!!");
         printf("\n\nPresiona una tecla para continuar");
         getch();
      }
   }
}