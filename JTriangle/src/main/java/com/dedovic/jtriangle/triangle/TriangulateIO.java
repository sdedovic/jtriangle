package com.dedovic.jtriangle.triangle;

/**
 * One-to-one mapping to the Triangle triangulateio struct.
 * Used to pass data into and out of the triangulate() procedure.
 */
public class TriangulateIO {
    public float[] pointList = new float[0];
    public float[] pointAttributeList = new float[0];
    public int[] pointMarkerList = new int[0];
    public int numberOfPoints = 0;
    public int numberOfPointAttributes = 0;

    public int[] triangleList = new int[0];
    public float[] triangleAttributeList = new float[0];
    public float[] triangleAreaList = new float[0];
    public int[] neighborList = new int[0];
    public int numberOfTriangles = 0;
    public int numberOfCorners = 3;
    public int numberOfTriangleAttributes = 0;

    public int[] segmentList = new int[0];
    public int[] segmentMarkerList = new int[0];
    public int numberOfSegments = 0;

    public float[] holeList = new float[0];
    public int numberOfHoles = 0;

    public float[] regionList = new float[0];
    public int numberOfRegions = 0;

    public int[] edgeList = new int[0];
    public int[] edgeMarkerList = new int[0];
    public float[] normList = new float[0];
    public int numberOfEdges = 0;
}
