//
// Created by stevan on 1/5/21.
//

#ifdef SINGLE
#define REAL float
#else /* not SINGLE */
#define REAL double
#endif /* not SINGLE */

#include "JTriangle.h"
#include "triangle.h"

/*
 * Class:     JTriangle
 * Method:    printFlags
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_JTriangle_printFlags(JNIEnv *env, jclass thisClass) {
    return env->NewStringUTF("fuck yeah");
}
