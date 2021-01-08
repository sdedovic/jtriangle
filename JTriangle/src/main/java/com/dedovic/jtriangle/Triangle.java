package com.dedovic.jtriangle;

import java.util.Formatter;

public class Triangle {
    private Point a;
    private Point b;
    private Point c;

    public Triangle(Point a, Point b, Point c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public Triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
        this.a = new Point(x1, y1);
        this.b = new Point(x2, y2);
        this.c = new Point(x3, y3);
    }

    public Triangle(float[] coords) {
        this.a = new Point(coords[0], coords[1]);
        this.b = new Point(coords[2], coords[3]);
        this.c = new Point(coords[4], coords[5]);
    }

    public Point getA() {
        return a;
    }

    public void setA(Point a) {
        this.a = a;
    }

    public Point getB() {
        return b;
    }

    public void setB(Point b) {
        this.b = b;
    }

    public Point getC() {
        return c;
    }

    public void setC(Point c) {
        this.c = c;
    }

    public Point[] toArray() {
        return new Point[]{this.a, this.b, this.c};
    }

    public float[] toFlatArray() {
        return new float[]{this.a.getX(), this.a.getY(), this.b.getX(), this.b.getY(), this.c.getX(), this.c.getY()};
    }

    @Override
    public String toString() {
        return new Formatter().format("[ %s, %s, %s]", this.a.toString(), this.b.toString(), this.c.toString()).toString();
    }
}
