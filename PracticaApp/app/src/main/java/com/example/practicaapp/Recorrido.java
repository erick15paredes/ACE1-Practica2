package com.example.practicaapp;

public class Recorrido {
    String movimiento;
    int index;
    int pushtime;

    public Recorrido(String movimiento, int index, int pushtime) {
        this.movimiento = movimiento;
        this.index=index;
        this.pushtime=pushtime;
    }

    public Recorrido() {
    }

    public String getMovimiento() {
        return movimiento;
    }

    public void setMovimiento(String movimiento) {
        this.movimiento = movimiento;
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public int getPushtime() {
        return pushtime;
    }

    public void setPushtime(int pushtime) {
        this.pushtime = pushtime;
    }
}
