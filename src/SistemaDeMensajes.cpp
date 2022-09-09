#include "SistemaDeMensajes.h"

// Completar...

SistemaDeMensajes::SistemaDeMensajes(){
    for(int i = 0; i<4; i++){
        _conns[i] = nullptr;
    }
}

void SistemaDeMensajes::registrarJugador(int id, std::string ip) {
    _conns[id] = new ConexionJugador(ip);
}

void SistemaDeMensajes::enviarMensaje(int id, std::string mensaje) {
    (*_conns[id]).enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

string SistemaDeMensajes::ipJugador(int id) const {
    return (*_conns[id]).ip();
}

// Ej. 2 correr con valgrind
SistemaDeMensajes::~SistemaDeMensajes() {
    for(ConexionJugador*& con : _conns){
        delete con;
    }
}
