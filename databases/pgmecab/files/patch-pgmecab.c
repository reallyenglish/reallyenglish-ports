--- ./pgmecab.c.orig	2006-02-15 00:36:39.000000000 +0900
+++ ./pgmecab.c	2010-06-20 06:30:19.000000000 +0900
@@ -7,7 +7,9 @@
 
 #include "postgres.h"
 #include "fmgr.h"
-
+#ifdef PG_MODULE_MAGIC
+PG_MODULE_MAGIC;
+#endif
 #include "mecab.h"
 
 #include <stdio.h>
@@ -18,18 +20,18 @@
 
 extern Datum pgmecab(PG_FUNCTION_ARGS);
 
-/* ��ʸ�����֤��ؿ� */
+/* ??ʸ?????֤??ؿ? */
 static Datum returnEmptyStr()
 {
 	text* emptyVal = (text*) palloc(VARHDRSZ);
-	VARATT_SIZEP(emptyVal) = VARHDRSZ;
+	SET_VARLENA_LEN(emptyVal, VARHDRSZ);
 	PG_RETURN_TEXT_P(emptyVal);
 }
 
 /**
- * mecab�ν�����̥����å��ޥ���
- * �����С����顼����PostgreSQL�Υ��顼��
- * ���Ϥ������Ȥ���ʤΤ��������Ϥ���ˡ��ʬ���餺������
+ * mecab?ν??????̥��??å??ޥ???
+ * ???????С????顼????PostgreSQL?Υ??顼??
+ * ???Ϥ??????Ȥ????ʤΤ��??????Ϥ???ˡ??ʬ???餺??????
  */
 #define CHECK(eval) if (! eval) { \
 	mecab_destroy(mecab); \
@@ -38,19 +40,19 @@
 
 Datum pgmecab(PG_FUNCTION_ARGS)
 {
-	/* NULL���褿��NULL���֤� */
+	/* NULL???褿??NULL???֤? */
 	if(PG_ARGISNULL(0))
 	{
 		PG_RETURN_NULL();
 	}
 	
-	/* ��������� */
+	/* ?????????? */
 	text* input_words = PG_GETARG_TEXT_P(0);
 	
-	/* �ºݤ�����ʸ����Υ�������NULL�����ߥ͡���ʬ��+1�򤹤� */
+	/* ?ºݤ?????ʸ?????Υ???????NULL?????ߥ͡???ʬ??+1?򤹤? */
 	size_t input_size = VARSIZE(input_words)-VARHDRSZ+1;
 	
-	/* ����ʸ���󤬶����ä����ʸ�����֤� */
+	/* ????ʸ???󤬶??��ä?????ʸ?????֤? */
 	if(input_size <= 1)
 	{
 		returnEmptyStr();
@@ -59,17 +61,17 @@
 	char* search_words = NULL;
 	
 	/*
-	 * ����ʸ�����ѥ������
-	 * palloc0�ϡ�0�ǽ�������줿����򤯤��
+	 * ????ʸ?????ѥ?????????
+	 * palloc0?ϡ?0?ǽ??������줿???????򤯤???
 	 */
 	search_words = (char*)palloc0(input_size * sizeof(char));
 	
-	/* ʸ���򥳥ԡ� */
+	/* ʸ???򥳥ԡ? */
 	memcpy(search_words, VARDATA(input_words), input_size-1);
 	
 	/*
-	 * mecab�ν����
-	 * ʬ�����񤭥⡼�ɤ�����
+	 * mecab?ν?????
+	 * ʬ???��񤭥⡼?ɤ?????
 	 */
 	const int mecav_argc = 3;
 	char* mecav_argv[] = {"mecab", "-O", "wakati"};
@@ -79,21 +81,21 @@
 	const char* mecab_result = mecab_sparse_tostr(mecab, search_words);
 	CHECK(mecab_result);
 	
-	/* ���Ϥ˻Ȥä�������� */
+	/* ???Ϥ˻Ȥä??????????? */
 	pfree(search_words);
 	search_words = NULL;
 	
-	/* ��̤򥳥ԡ� */
+	/* ???̤򥳥ԡ? */
 	size_t mecab_result_size = strlen(mecab_result);
 	
-	/* �֤�����Υ������ */
+	/* ?֤??????Υ????????? */
 	text* return_val = (text *) palloc(VARHDRSZ + mecab_result_size * sizeof(char));
-	VARATT_SIZEP(return_val) = VARHDRSZ + mecab_result_size * sizeof(char);
+	SET_VARLENA_LEN(return_val, VARHDRSZ + mecab_result_size * sizeof(char));
 	
-	/* ��̤򥳥ԡ� */
+	/* ???̤򥳥ԡ? */
 	memcpy((void*)VARDATA(return_val), mecab_result, mecab_result_size);
 	
-	/* MeCab�θ���� */
+	/* MeCab?θ????? */
 	mecab_destroy(mecab);
 	
 	PG_RETURN_TEXT_P(return_val);
