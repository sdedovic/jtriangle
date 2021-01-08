package com.dedovic.jtriangle;

import java.util.Formatter;

public class Point {
    private float x;
    private float y;

    public Point(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public static Point from(float x, float y) {
        return new Point(x, y);
    }

    public float getX() {
        return x;
    }

    public void setX(float x) {
        this.x = x;
    }

    public float getY() {
        return y;
    }

    public void setY(float y) {
        this.y = y;
    }

    public float[] toArray() {
        return new float[]{this.x, this.y};
    }

    @Override
    public String toString() {
        return new Formatter().format("[%.2f, %.2f]", this.x, this.y).toString();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Point)) return false;

        Point point = (Point) o;
        return Float.compare(point.getX(), getX()) == 0 && Float.compare(point.getY(), getY()) == 0;
    }

    @Override
    public int hashCode() {
        long asLong = java.lang.Double.doubleToLongBits(getY());
        asLong = asLong * 31 ^ java.lang.Double.doubleToLongBits(getX());
        return (int) ((asLong >> 32) ^ asLong);
    }
}
