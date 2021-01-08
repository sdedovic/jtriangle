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
* Class:     com_dedovic_jtriangle_triangle_JTriangle
* Method:    triangulateInternal
* Signature: (Ljava/lang/String;Lcom/dedovic/jtriangle/triangle/TriangulateIO;Lcom/dedovic/jtriangle/triangle/TriangulateIO;Lcom/dedovic/jtriangle/triangle/TriangulateIO;)V
*/
JNIEXPORT void JNICALL
Java_com_dedovic_jtriangle_triangle_JTriangle_triangulateInternal
(JNIEnv *env, jclass _, jstring flags, jobject inObj, jobject outObj, jobject voroutObj)
{

    struct triangulateio in{}, out{}, vorout{};

    // field ids
    // TODO: cache these
    jclass triangulateIOClass = env->GetObjectClass(inObj);

    jfieldID fieldPointList = env->GetFieldID(triangulateIOClass, "pointList", "[F");
    jfieldID fieldPointAttributeList = env->GetFieldID(triangulateIOClass, "pointAttributeList", "[F");
    jfieldID fieldPointMarkerList = env->GetFieldID(triangulateIOClass, "pointMarkerList", "[I");
    jfieldID fieldNumberOfPoints = env->GetFieldID(triangulateIOClass, "numberOfPoints", "I");
    jfieldID fieldNumberOfPointAttributes = env->GetFieldID(triangulateIOClass, "numberOfPointAttributes", "I");

    jfieldID fieldTriangleList = env->GetFieldID(triangulateIOClass, "triangleList", "[I");
    jfieldID fieldTriangleAttributeList = env->GetFieldID(triangulateIOClass, "triangleAttributeList", "[F");
    jfieldID fieldTriangleAreaList = env->GetFieldID(triangulateIOClass, "triangleAreaList", "[F");
    jfieldID fieldNeighborList = env->GetFieldID(triangulateIOClass, "neighborList", "[I");
    jfieldID fieldNumberOfTriangles = env->GetFieldID(triangulateIOClass, "numberOfTriangles", "I");
    jfieldID fieldNumberOfCorners = env->GetFieldID(triangulateIOClass, "numberOfCorners", "I");
    jfieldID fieldNumberOfTriangleAttributes = env->GetFieldID(triangulateIOClass, "numberOfTriangleAttributes", "I");

    jfieldID fieldSegmentList = env->GetFieldID(triangulateIOClass, "segmentList", "[I");
    jfieldID fieldSegmentMarkerList = env->GetFieldID(triangulateIOClass, "segmentMarkerList", "[I");
    jfieldID fieldNumberOfSegments = env->GetFieldID(triangulateIOClass, "numberOfSegments", "I");

    jfieldID fieldHoleList = env->GetFieldID(triangulateIOClass, "holeList", "[F");
    jfieldID fieldNumberOfHoles = env->GetFieldID(triangulateIOClass, "numberOfHoles", "I");

    jfieldID fieldRegionList = env->GetFieldID(triangulateIOClass, "regionList", "[F");
    jfieldID fieldNumberOfRegions = env->GetFieldID(triangulateIOClass, "numberOfRegions", "I");

    jfieldID fieldEdgeList = env->GetFieldID(triangulateIOClass, "edgeList", "[I");
    jfieldID fieldEdgeMarkerList = env->GetFieldID(triangulateIOClass, "edgeMarkerList", "[I");
    jfieldID fieldNormList = env->GetFieldID(triangulateIOClass, "normList", "[F");
    jfieldID fieldNumberOfEdges = env->GetFieldID(triangulateIOClass, "numberOfEdges", "I");


    // references to buffers so we can easily release
    auto pointArray = (jfloatArray) (env->GetObjectField(inObj, fieldPointList));
    jfloat *pointBuffer = pointArray != nullptr ? env->GetFloatArrayElements(pointArray, nullptr) : nullptr;

    auto pointAttributeArray = (jfloatArray) (env->GetObjectField(inObj, fieldPointAttributeList));
    jfloat *pointAttributeBuffer = pointAttributeArray != nullptr ? env->GetFloatArrayElements(pointAttributeArray, nullptr) : nullptr;

    auto pointMarkerArray = (jintArray) (env->GetObjectField(inObj, fieldPointMarkerList));
    jint *pointMarkerBuffer = pointMarkerArray != nullptr ? env->GetIntArrayElements(pointMarkerArray, nullptr) : nullptr;

    auto triangleArray = (jintArray) (env->GetObjectField(inObj, fieldTriangleList));
    jint *triangleBuffer = triangleArray != nullptr ? env->GetIntArrayElements(triangleArray, nullptr) : nullptr;

    auto triangleAttributeArray = (jfloatArray) (env->GetObjectField(inObj, fieldTriangleAttributeList));
    jfloat *triangleAttributeBuffer = triangleAttributeArray != nullptr ? env->GetFloatArrayElements(triangleAttributeArray, nullptr) : nullptr;

    auto triangleAreaArray = (jfloatArray) (env->GetObjectField(inObj, fieldTriangleAreaList));
    jfloat *triangleAreaBuffer = triangleAreaArray != nullptr ? env->GetFloatArrayElements(triangleAreaArray, nullptr) : nullptr;

    auto segmentArray = (jintArray) (env->GetObjectField(inObj, fieldSegmentList));
    jint *segmentBuffer = segmentArray != nullptr ? env->GetIntArrayElements(segmentArray, nullptr) : nullptr;

    auto segmentMarkerArray = (jintArray) (env->GetObjectField(inObj, fieldSegmentMarkerList));
    jint *segmentMarkerBuffer = segmentMarkerArray != nullptr ? env->GetIntArrayElements(segmentMarkerArray, nullptr) : nullptr;

    auto holeArray = (jfloatArray) (env->GetObjectField(inObj, fieldHoleList));
    jfloat *holeBuffer = holeArray != nullptr ? env->GetFloatArrayElements(holeArray, nullptr) : nullptr;

    auto regionArray = (jfloatArray) (env->GetObjectField(inObj, fieldRegionList));
    jfloat *regionBuffer = regionArray != nullptr ? env->GetFloatArrayElements(regionArray, nullptr) : nullptr;


    // build input
    in.numberofpoints = env->GetIntField(inObj, fieldNumberOfPoints);
    in.numberofpointattributes = env->GetIntField(inObj, fieldNumberOfPointAttributes);
    in.pointlist = pointBuffer;
    in.pointattributelist = pointAttributeBuffer;
    in.pointmarkerlist = pointMarkerBuffer;

    in.trianglelist = triangleBuffer;
    in.triangleattributelist = triangleAttributeBuffer;
    in.trianglearealist = triangleAreaBuffer;
    in.numberoftriangles = env->GetIntField(inObj, fieldNumberOfTriangles);
    in.numberofcorners = env->GetIntField(inObj, fieldNumberOfCorners);
    in.numberoftriangleattributes = env->GetIntField(inObj, fieldNumberOfTriangleAttributes);

    in.segmentlist = segmentBuffer;
    in.segmentmarkerlist = segmentMarkerBuffer;
    in.numberofsegments = env->GetIntField(inObj, fieldNumberOfSegments);

    in.holelist = holeBuffer;
    in.numberofholes = env->GetIntField(inObj, fieldNumberOfHoles);

    in.regionlist = regionBuffer;
    in.numberofregions = env->GetIntField(inObj, fieldNumberOfRegions);


    // build outputs
    out.pointlist = nullptr;
    out.pointattributelist = nullptr;
    out.pointmarkerlist = nullptr;
    out.trianglelist = nullptr;
    out.triangleattributelist = nullptr;
    out.neighborlist = nullptr;
    out.segmentlist = nullptr;
    out.segmentmarkerlist = nullptr;
    out.edgelist = nullptr;
    out.edgemarkerlist = nullptr;

    vorout.pointlist = nullptr;
    vorout.pointattributelist = nullptr;
    vorout.pointmarkerlist = nullptr;
    vorout.trianglelist = nullptr;
    vorout.triangleattributelist = nullptr;
    vorout.neighborlist = nullptr;
    vorout.segmentlist = nullptr;
    vorout.segmentmarkerlist = nullptr;
    vorout.edgelist = nullptr;
    vorout.normlist = nullptr;


    // execute
    char *flagsBuffer = strdup(env->GetStringUTFChars(flags, nullptr));
    triangulate(flagsBuffer, &in, &out, &vorout);


    // copy data from out to JVM
    if (out.pointlist) {
        jfloatArray outPointArray = env->NewFloatArray(out.numberofpoints * 2);
        env->SetFloatArrayRegion(outPointArray, 0, out.numberofpoints * 2, out.pointlist);
        env->SetObjectField(outObj, fieldPointList, outPointArray);
    }
    if (out.pointattributelist) {
        jfloatArray outPointAttributeArray = env->NewFloatArray(out.numberofpointattributes);
        env->SetFloatArrayRegion(outPointAttributeArray, 0, out.numberofpointattributes, out.pointattributelist);
        env->SetObjectField(outObj, fieldPointAttributeList, outPointAttributeArray);
    }
    if (out.pointmarkerlist) {
        jintArray outPointMarkerArray = env->NewIntArray(out.numberofpoints);
        env->SetIntArrayRegion(outPointMarkerArray, 0, out.numberofpoints, out.pointmarkerlist);
        env->SetObjectField(outObj, fieldPointMarkerList, outPointMarkerArray);
    }
    env->SetIntField(outObj, fieldNumberOfPoints, out.numberofpoints);
    env->SetIntField(outObj, fieldNumberOfPointAttributes, out.numberofpointattributes);

    if (out.trianglelist) {
        jintArray outTriangleArray = env->NewIntArray(out.numberoftriangles * out.numberofcorners);
        env->SetIntArrayRegion(outTriangleArray, 0, out.numberoftriangles * out.numberofcorners, out.trianglelist);
        env->SetObjectField(outObj, fieldTriangleList, outTriangleArray);
    }
    if (out.triangleattributelist) {
        jfloatArray outTriangleAttributeArray = env->NewFloatArray(out.numberoftriangleattributes);
        env->SetFloatArrayRegion(outTriangleAttributeArray, 0, out.numberoftriangleattributes, out.triangleattributelist);
        env->SetObjectField(outObj, fieldTriangleAttributeList, outTriangleAttributeArray);
    }
    if (out.neighborlist) {
        jintArray outNeighborArray = env->NewIntArray(out.numberoftriangles * 3);
        env->SetIntArrayRegion(outNeighborArray, 0, out.numberoftriangles * 3, out.neighborlist);
        env->SetObjectField(outObj, fieldNeighborList, outNeighborArray);
    }
    env->SetIntField(outObj, fieldNumberOfTriangles, out.numberoftriangles);
    env->SetIntField(outObj, fieldNumberOfCorners, out.numberofcorners);
    env->SetIntField(outObj, fieldNumberOfTriangleAttributes, out.numberoftriangleattributes);

    if (out.segmentlist) {
        jintArray outSegmentArray = env->NewIntArray(out.numberofsegments * 2);
        env->SetIntArrayRegion(outSegmentArray, 0, out.numberofsegments * 2, out.segmentlist);
        env->SetObjectField(outObj, fieldSegmentList, outSegmentArray);
    }
    if (out.segmentmarkerlist) {
        jintArray outSegmentMarkerArray = env->NewIntArray(out.numberofsegments);
        env->SetIntArrayRegion(outSegmentMarkerArray, 0, out.numberofsegments, out.segmentmarkerlist);
        env->SetObjectField(outObj, fieldSegmentMarkerList, outSegmentMarkerArray);
    }
    env->SetIntField(outObj, fieldNumberOfSegments, out.numberofsegments);

    if (out.edgelist) {
        jintArray outEdgeArray = env->NewIntArray(out.numberofedges * 2);
        env->SetIntArrayRegion(outEdgeArray, 0, out.numberofedges * 2, out.edgelist);
        env->SetObjectField(outObj, fieldEdgeList, outEdgeArray);
    }
    if (out.edgemarkerlist) {
        jintArray outEdgeMarkerList = env->NewIntArray(out.numberofedges);
        env->SetIntArrayRegion(outEdgeMarkerList, 0, out.numberofedges, out.edgemarkerlist);
        env->SetObjectField(outObj, fieldEdgeMarkerList, outEdgeMarkerList);
    }
    env->SetIntField(outObj, fieldNumberOfEdges, out.numberofedges);


    // copy data from vorout to JVM
    if (vorout.pointlist) {
        jfloatArray voroutPointArray = env->NewFloatArray(vorout.numberofpoints * 2);
        env->SetFloatArrayRegion(voroutPointArray, 0, vorout.numberofpoints * 2, vorout.pointlist);
        env->SetObjectField(voroutObj, fieldPointList, voroutPointArray);
    }
    if (vorout.pointattributelist) {
        jfloatArray voroutPointAttributeArray = env->NewFloatArray(vorout.numberofpointattributes);
        env->SetFloatArrayRegion(voroutPointAttributeArray, 0, vorout.numberofpointattributes, vorout.pointattributelist);
        env->SetObjectField(voroutObj, fieldPointAttributeList, voroutPointAttributeArray);
    }
    env->SetIntField(voroutObj, fieldNumberOfPoints, vorout.numberofpoints);
    env->SetIntField(voroutObj, fieldNumberOfPointAttributes, vorout.numberofpointattributes);

    if (vorout.edgelist) {
        jintArray voroutEdgeArray = env->NewIntArray(vorout.numberofedges * 2);
        env->SetIntArrayRegion(voroutEdgeArray, 0, vorout.numberofedges * 2, vorout.edgelist);
        env->SetObjectField(voroutObj, fieldEdgeList, voroutEdgeArray);
    }
    if (vorout.normlist) {
        jfloatArray voroutNormArray = env->NewFloatArray(vorout.numberofedges * 2);
        env->SetFloatArrayRegion(voroutNormArray, 0, vorout.numberofedges * 2, vorout.normlist);
        env->SetObjectField(voroutObj, fieldNormList, voroutNormArray);
    }
    env->SetIntField(voroutObj, fieldNumberOfEdges, vorout.numberofedges);


    // release JVM input
    if (pointBuffer) env->ReleaseFloatArrayElements(pointArray, pointBuffer, 0);
    if (pointAttributeBuffer) env->ReleaseFloatArrayElements(pointAttributeArray, pointAttributeBuffer, 0);
    if (pointMarkerBuffer) env->ReleaseIntArrayElements(pointMarkerArray, pointMarkerBuffer, 0);

    if (triangleBuffer) env->ReleaseIntArrayElements(triangleArray, triangleBuffer, 0);
    if (triangleAttributeBuffer) env->ReleaseFloatArrayElements(triangleAttributeArray, triangleAttributeBuffer, 0);
    if (triangleAreaBuffer) env->ReleaseFloatArrayElements(triangleAreaArray, triangleAreaBuffer, 0);

    if (segmentBuffer) env->ReleaseIntArrayElements(segmentArray, segmentBuffer, 0);
    if (segmentMarkerBuffer) env->ReleaseIntArrayElements(segmentMarkerArray, segmentMarkerBuffer, 0);

    if (holeBuffer) env->ReleaseFloatArrayElements(holeArray, holeBuffer, 0);
    if (regionBuffer) env->ReleaseFloatArrayElements(regionArray, regionBuffer, 0);


    // release Triangle allocated
    free(out.pointlist);
    free(out.pointattributelist);
    free(out.pointmarkerlist);
    free(out.trianglelist);
    free(out.triangleattributelist);
    free(out.neighborlist);
    free(out.segmentlist);
    free(out.segmentmarkerlist);
    free(out.edgelist);
    free(out.edgemarkerlist);

    free(vorout.pointlist);
    free(vorout.pointattributelist);
    free(vorout.pointmarkerlist);
    free(vorout.trianglelist);
    free(vorout.triangleattributelist);
    free(vorout.neighborlist);
    free(vorout.segmentlist);
    free(vorout.segmentmarkerlist);
    free(vorout.edgelist);
    free(vorout.normlist);
}