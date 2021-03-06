/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_ogre4j_SubMesh */

#ifndef _Included_org_ogre4j_SubMesh
#define _Included_org_ogre4j_SubMesh
#ifdef __cplusplus
extern "C" {
#endif
/* Inaccessible static: table */
/*
 * Class:     org_ogre4j_SubMesh
 * Method:    addBoneAssignment
 * Signature: (IISF)V
 */
JNIEXPORT void JNICALL Java_org_ogre4j_SubMesh_addBoneAssignment
  (JNIEnv *, jclass, jint, jint, jshort, jfloat);

/*
 * Class:     org_ogre4j_SubMesh
 * Method:    getIndexData
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_SubMesh_getIndexData
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_ogre4j_SubMesh
 * Method:    getUseSharedVertices
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_org_ogre4j_SubMesh_getUseSharedVertices
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_ogre4j_SubMesh
 * Method:    getVertexData
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_org_ogre4j_SubMesh_getVertexData
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_ogre4j_SubMesh
 * Method:    setMaterialName
 * Signature: (ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_ogre4j_SubMesh_setMaterialName
  (JNIEnv *, jclass, jint, jstring);

/*
 * Class:     org_ogre4j_SubMesh
 * Method:    setUseSharedVertices
 * Signature: (IZ)V
 */
JNIEXPORT void JNICALL Java_org_ogre4j_SubMesh_setUseSharedVertices
  (JNIEnv *, jclass, jint, jboolean);

/*
 * Class:     org_ogre4j_SubMesh
 * Method:    setVertexData
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_org_ogre4j_SubMesh_setVertexData
  (JNIEnv *, jclass, jint, jint);

#ifdef __cplusplus
}
#endif
#endif
