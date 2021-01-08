import static org.junit.Assert.assertEquals;

import org.junit.Assert;
import org.junit.Test;

import java.util.Formatter;

public class JTriangleTest {
    @Test
    public void evaluatesExpression() {
        String flags = JTriangle.printFlags();
        Assert.assertEquals("test foobar", flags);
    }

    @Test
    public void testTriangulation() {
        float[] points = {
                0f,   0f,
                10f,  0f,
                10f, 10f,
                0f,  10f
        };

        int[] trianglesCoords = JTriangle.triangulateV1(points);
        for (int i=0; i<trianglesCoords.length/3; i++) {
            int indexP1 = trianglesCoords[i*3];
            int indexP2 = trianglesCoords[(i*3)+1];
            int indexP3 = trianglesCoords[(i*3)+2];
            System.out.println(new Formatter().format("TRIANGLE: [ %d, %d, %d ]", indexP1, indexP2, indexP3));
            System.out.println(new Formatter().format("TRIANGLE: [\n\t[%.2f %.2f]\n\t[%.2f %.2f]\n\t[%.2f %.2f]\n]",
                    points[indexP1*2], points[indexP1*2+1], points[indexP2*2], points[indexP2*2+1], points[indexP3*2], points[indexP3*2+1]));
        }
    }
}