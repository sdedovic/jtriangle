package com.dedovic.jtriangle;

import com.dedovic.jtriangle.triangle.JTriangle;
import com.dedovic.jtriangle.triangle.TriangulateIO;

import java.util.ArrayList;
import java.util.List;

/**
 * This class provides a high-level interface to the Triangle library used for general-purpose polygon triangulation.
 */
public class Triangulate {

    /**
     * Triangulate a simple (non-self-intersecting) polygon.
     * @param points The input polygon definition. The first and last points should not repeat.
     * @return A list of triangles, the output of triangulating the polygon.
     */
    public static List<Triangle> triangulate(List<Point> points) {
        int numPoints = points.size();
        float[] flatPoints = new float[numPoints * 2];
        for (int i = 0; i < numPoints; i++) {
            Point point = points.get(i);
            flatPoints[i*2] = point.getX();
            flatPoints[(i*2)+1] = point.getY();
        }

        TriangulateIO in = new TriangulateIO();
        in.pointList = flatPoints;
        in.numberOfPoints = numPoints;

        TriangulateIO out = new TriangulateIO();
        TriangulateIO vorout = new TriangulateIO();
        JTriangle.triangulate("pczQ", in, out, vorout);

        List<Triangle> triangles = new ArrayList<>(out.numberOfTriangles);
        for (int i = 0; i < out.numberOfTriangles; i++) {
            int indexPointA = out.triangleList[i*3];
            int indexPointB = out.triangleList[(i*3)+1];
            int indexPointC = out.triangleList[(i*3)+2];

            Point a = new Point(out.pointList[indexPointA*2], out.pointList[(indexPointA*2)+1]);
            Point b = new Point(out.pointList[indexPointB*2], out.pointList[(indexPointB*2)+1]);
            Point c = new Point(out.pointList[indexPointC*2], out.pointList[(indexPointC*2)+1]);

            triangles.add(new Triangle(a, b, c));
        }

        return triangles;
    }
}
