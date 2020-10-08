#ifndef BOTELLA_CLASS_H_INCLUDED
#define BOTELLA_CLASS_H_INCLUDED

class Botella{
private:
    float Capacidad;
    float Ocupacion;
    bool Tapada;
public:
    float Llenar(float Cap);
    void Vaciar();
    bool Tapar(int auxTap3);
    bool Destapar(int auxTap3);
    void darCapacidad();
    void darOcupacion();
    bool darDisponibilidad();
    void estado();
    Botella(float Cap, float Ocu, bool Tap);
    //~Botella();

};







#endif // BOTELLA_CLASS_H_INCLUDED
