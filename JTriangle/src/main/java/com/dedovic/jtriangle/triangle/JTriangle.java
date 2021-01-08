package com.dedovic.jtriangle.triangle;

public class JTriangle {
    static {
        String libraryBaseName = "JTriangle-" + getJTriangleVersion();
            String libraryName = LibUtils.createPlatformLibraryName(libraryBaseName);
            LibUtils.loadLibrary(libraryName);
    }

    public static String getJTriangleVersion() {
        return "0.1.6";
    }

    /* Private constructor to prevent instantiation */
    private JTriangle() { }

    /**
     * <p>Call the triangulate proceduce in the Triangle library, passing all supplied parameters.</p>
     *
     * <p>Some helpful tips:
     * <ul>
     *  <li>You'll probably find it convenient to use the 'z' switch so that points (and other items) are numbered
     *          from zero.  This simplifies indexing, because the first item of any type always starts at index [0]
     *          of the corresponding array, whether that item's number is zero or one.
     *  <li>You'll probably want to use the 'Q' (quiet) switch in your final code, but you can take advantage of
     *          Triangle's printed output (including the 'V' switch) while debugging.
     *  <li>The 'I' (no iteration numbers) and 'g' (.off file output) switches have no effect.
     * </ul>
     * </p>
     *
     * @param flags - command line switches for Triangle.
     *                  See <a href="https://www.cs.cmu.edu/~quake/triangle.switch.html">the Triangle docs</a>}
     *                  for more information.
     * @param in - in
     * @param out - out
     * @param voronoiOut - vorout
     */
    public static void triangulate(String flags, TriangulateIO in, TriangulateIO out, TriangulateIO voronoiOut) {
        triangulateInternal(flags, in, out, voronoiOut);

        // doing this here instead of in the native code for simplicity
        System.arraycopy(in.holeList, 0, out.holeList, 0, in.holeList.length);
        System.arraycopy(in.holeList, 0, voronoiOut.holeList, 0, voronoiOut.holeList.length);

        System.arraycopy(in.regionList, 0, out.regionList, 0, out.regionList.length);
        System.arraycopy(in.regionList, 0, voronoiOut.regionList, 0, voronoiOut.regionList.length);

        out.numberOfHoles = in.numberOfHoles;
        out.numberOfRegions = in.numberOfRegions;
        voronoiOut.numberOfHoles = in.numberOfHoles;
        voronoiOut.numberOfRegions = in.numberOfRegions;
    }

    private static native void triangulateInternal(String flags, TriangulateIO in, TriangulateIO out, TriangulateIO voronoiOut);
}