#ifndef GEOMETRIA_HPP
#define GEOMETRIA_HPP

#include <iostream>
#include <cmath>

class Punto3D {
private:
    double x, y, z;
    unsigned char color[3];
public:
    Punto3D() : x(0.0), y(0.0), z(0.0) {
        color[0] =  color[1] = color[2] = 0;
    }
    Punto3D(double x_arg, double y_arg, double z_arg, unsigned char r, unsigned char g, unsigned char b){
        x= x_arg;
        y= y_arg;
        z= z_arg;

        color[0]=r;
        color[1]=g;
        color[2]=b;

    }

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    void setX(double val){
        x= val;
    }
    void setY(double val){
        y= val; 
    }
    void setZ(double val){
        z= val;
    }

    unsigned char getR() const { return color[0]; }
    unsigned char getG() const { return color[1]; }
    unsigned char getB() const { return color[2]; }

    void setColor(unsigned char r, unsigned char g, unsigned char b){
        color[0]= r; 
        color[1]=g; 
        color[2]=b;
    }  
    double distancia(const Punto3D& otro) const{

        double dx= x - otro.x;
        double dy= y - otro.y;
        double dz= z - otro.z;

        double dist= pow((dx*dx)+(dy*dy)+(dz*dz),2);
        return dist;
    }
    bool operator==(const Punto3D& otro) const{

        //double e= 0.000001;
        double e =1.0E-6;

        double diffx= fabs(x-otro.x); 
        double diffy= fabs(y-otro.y); 
        double diffz= fabs(z-otro.z); 
        


        if((diffx < e && color[0]== otro.color[0]) && (diffy < e && color[1]== otro.color[1]) && (diffz < e && color[2]== otro.color[2])){
            return true; 
        }
        else{
            return false; 
        }
        

    }
    friend std::ostream& operator<<(std::ostream& out, const Punto3D& p) {
        out << "(" << p.x << ", " << p.y << ", " << p.z << ") ["
            << (int)p.color[0] << ", " << (int)p.color[1] << ", "
            << (int)p.color[2] << "]";
        return out;
    }
};

class Linea3D {
private:
    Punto3D p1;
    Punto3D p2;
    unsigned char color[3];
public:
    Linea3D() {
        color[0] = color[1] = color[2] = 0;
    }
    Linea3D(Punto3D pt1, Punto3D pt2, unsigned char r, unsigned char g, unsigned char b){
        p1 = pt1; 
        p2 = pt2; 

        color[0]=r;
        color[1]=g; 
        color[2]=b; 
    }

    Punto3D getP1() const { return p1; }
    Punto3D getP2() const { return p2; }

    void setP1(Punto3D pt){
        p1= pt;
    }
    void setP2(Punto3D pt){
        p2= pt;
    }
    unsigned char getR() const { return color[0]; }
    unsigned char getG() const { return color[1]; }
    unsigned char getB() const { return color[2]; }
    void setColor(unsigned char r, unsigned char g, unsigned char b){
        color[0]= r; 
        color[1]=g; 
        color[1]=b;
    }
    int buscarEnArreglo(const Linea3D* arreglo, int tamano) const{
        for(int i=0; i < tamano; i++){

            if(*this == arreglo[i]){
                return i; 
            }
            else{
                return -1; 
            }
        }
    }
    bool operator==(const Linea3D& otro) const{
        if((p1== otro.p1 && p2 == otro.p2)  && (color[0]==otro.color[0] && color[1]==otro.color[1] && color[2]==otro.color[2])){
            return true;
        }
        else{
            return false;
        }
    }
    friend std::ostream& operator<<(std::ostream& out, const Linea3D& l) {
        out << "Linea de " << l.p1 << " a " << l.p2 << " con Color ["
            << (int)l.color[0] << ", " << (int)l.color[1] << ", " << (int)l.color[2] << "]";
        return out;
    }
};

#endif

