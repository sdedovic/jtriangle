//
// Created by stevan on 1/5/21.
//

extern "C" {
    #include "triangle/triangle.h"
//    void triangulate(char *, struct triangulateio *, struct triangulateio *, struct triangulateio *);
}

#include "JTriangle.h"
#include <cstdlib>
#include <cstring>


#ifdef SINGLE
#define REAL float
#else /* not SINGLE */
#define REAL double
#endif /* not SINGLE */

/*
 * Class:     JTriangle
 * Method:    printFlags
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_JTriangle_printFlags(JNIEnv *env, jclass thisClass)
{
    return env->NewStringUTF("test foobar");
}

/*
 * Class:     JTriangle
 * Method:    triangulateV1
 * Signature: ([F)[I
 */
JNIEXPORT jintArray JNICALL Java_JTriangle_triangulateV1(JNIEnv *env, jclass thisClass, jfloatArray points)
{
    jfloat* pointsBuffer = env->GetFloatArrayElements(points, NULL);

    struct triangulateio in{}, out{};
    in.numberofpoints = env->GetArrayLength(points) / 2;;
    in.numberofpointattributes = 0;
    in.pointlist = pointsBuffer;
    in.pointattributelist = nullptr;
    in.pointmarkerlist = nullptr;

    in.pointattributelist = nullptr;
    in.pointmarkerlist = nullptr;

    in.numberofsegments = 0;
    in.numberofholes = 0;
    in.numberofregions = 0;
    in.regionlist = nullptr;

    out.trianglelist = nullptr;
    out.pointlist = nullptr;            /* Not needed if -N switch used. */
    out.pointmarkerlist = nullptr;       /* Not needed if -N or -B switch used. */
    /* Needed only if segments are output (-p or -c) and -P not used: */
    out.segmentlist = nullptr;
    /* Needed only if segments are output (-p or -c) and -P and -B not used: */
    out.segmentmarkerlist = (int *) nullptr;
    out.edgelist = (int *) nullptr;

    // call triangulate
    char *flags = strdup("pcz");
    triangulate(flags, &in, &out, nullptr);

    // copy data to java memory
    jintArray result = env->NewIntArray(out.numberoftriangles*out.numberofcorners);
    env->SetIntArrayRegion(result, 0, out.numberoftriangles*out.numberofcorners, out.trianglelist);

    // free all memory used
    env->ReleaseFloatArrayElements(points, pointsBuffer, 0);

    free(out.trianglelist);
    free(out.pointlist);
    free(out.pointmarkerlist);
    free(out.segmentlist);
    free(out.segmentmarkerlist);
    free(out.edgelist);

    return result;
}
