#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char nroinscrip[5];
    char apellido[10];
    int inasist;
} inscriptos;

typedef struct
{
    char nroinscrip[5];
    char apellido[10];
} asistencia;

void leeinscriptos ()
{
    inscriptos ins;
    FILE *archtxt,*archbin;
    archtxt=fopen("inscriptos.txt","rt");
    if (archtxt!=NULL)
    {
        archbin=fopen("inscriptos.dat","wb");
        while(fscanf(archtxt,"%s %s %d",ins.nroinscrip,ins.apellido,&ins.inasist)==3)
        {
            fwrite(&ins,sizeof(inscriptos),1,archbin);
        }
        fclose(archtxt);
        fclose(archbin);
    }
}


void leeasistencia ()
{
    asistencia asi;
    FILE *archtxt,*archbin;
    archtxt=fopen("asistencia.txt","rt");
    if (archtxt!=NULL)
    {
        archbin=fopen("asistencia.dat","wb");
        while(fscanf(archtxt,"%s %s",asi.nroinscrip,asi.apellido)==2)
        {
            fwrite(&asi,sizeof(asistencia),1,archbin);
        }
        fclose(archtxt);
        fclose(archbin);
    }
}

void enfrenta()
{
    FILE *archinscrip=fopen("inscriptos.dat","rb");
    FILE *archasist=fopen("asistencia.dat","rb");
    FILE *archactual;
    inscriptos ins;
    asistencia asi;
    if (archinscrip!=NULL || archasist!=NULL)
    {
        fread(&ins,sizeof(inscriptos),1,archinscrip);
        fread(&asi,sizeof(asistencia),1,archasist);
        while(!feof(archinscrip) || !feof(archasist))
        {
            if(strcmp(asi.nroinscrip,ins.nroinscrip)==0)  // lo encontro FUE
            {
                fread(&ins,sizeof(inscriptos),1,archinscrip);
                fread(&asi,sizeof(asistencia),1,archasist);
                //plantear archivo actualizacion.

            }
            else if (strcmp(asi.nroinscrip,ins.nroinscrip)>0)  //no encontro y avanza en inscripcion NO FUE.
            {
                fread(&ins,sizeof(inscriptos),1,archinscrip);


            }
            else
            {
                fread(&asi,sizeof(asistencia),1,archasist);  // no encontro y avanza en asistencia fue a la clase pero no esta inscripto error.
            }
        }
    }
}
























int main()
{
    return 0;
}
