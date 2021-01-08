class JTriangle {
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

    public static native String printFlags();

    public static native int[] triangulateV1(float[] nodes);
}