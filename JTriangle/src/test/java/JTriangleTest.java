import static org.junit.Assert.assertEquals;

import org.junit.Assert;
import org.junit.Test;

public class JTriangleTest {
    @Test
    public void evaluatesExpression() {
        String flags = JTriangle.printFlags();
        Assert.assertNotNull(flags);
    }
}