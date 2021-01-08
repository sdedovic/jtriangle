package com.dedovic.jtriangle;

import org.junit.Assert;
import org.junit.Test;

import java.util.List;

public class TriangulateTest {
    @Test
    public void testTriangulation() {
        List<Triangle> triangles = Triangulate.triangulate(
            List.of(
                Point.from(0, 0),
                Point.from(0, 10),
                Point.from(10, 10),
                Point.from(10, 0)
            )
        );

        Assert.assertEquals(2, triangles.size());
        Assert.assertNotEquals(triangles.get(0), triangles.get(1));
    }
}