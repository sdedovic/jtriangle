package com.dedovic.jtriangle.triangle;

import org.junit.Assert;
import org.junit.Test;

public class JTriangleTest {
    float[] points = {
            0f,   0f,
            10f,  0f,
            10f, 10f,
            0f,  10f
    };

    @Test
    public void testTriangulation() {
        TriangulateIO in = new TriangulateIO();
        TriangulateIO out = new TriangulateIO();
        TriangulateIO voronoi = new TriangulateIO();

        in.pointList = points;
        in.numberOfPoints = 4;
        in.pointAttributeList = null;

        Assert.assertNotEquals(4, out.numberOfPoints);
        JTriangle.triangulate("pczQ", in, out, voronoi);
        Assert.assertEquals(4, out.numberOfPoints);
        Assert.assertEquals(4, in.numberOfPoints);
    }
}