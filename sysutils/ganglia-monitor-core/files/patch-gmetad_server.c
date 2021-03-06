
$FreeBSD: ports/sysutils/ganglia-monitor-core/files/patch-gmetad_server.c,v 1.1 2009/01/30 03:56:34 brooks Exp $

--- gmetad/server.c.orig
+++ gmetad/server.c
@@ -370,14 +370,13 @@
    
 /* sacerdoti: This function does a tree walk while respecting the filter path.
  * Will return valid XML even if we have chosen a subtree. Since tree depth is
- * bounded, this function guarantees O(1) search time. The recursive structure 
- * does not require any memory allocations. 
+ * bounded, this function guarantees O(1) search time.
  */
 static int
 process_path (client_t *client, char *path, datum_t *myroot, datum_t *key)
 {
    char *p, *q, *pathend;
-   char element[256];
+   char *element;
    int rc, len;
    datum_t *found;
    datum_t findkey;
@@ -419,6 +418,9 @@
          if (!q) q=pathend;
       
          len = q-p;
+         element = malloc(len + 1);
+         if ( element == NULL )
+             return 1;
          strncpy(element, p, len);
          element[len] = '\0';
       
@@ -440,6 +442,7 @@
             {
                rc = process_path(client, 0, myroot, NULL);
             }
+         free(element);
       }
    if (rc) return 1;
 
@@ -537,7 +540,7 @@
    socklen_t len;
    client_t client;
    char remote_ip[16];
-   char request[REQUESTLEN];
+   char request[REQUESTLEN + 1];
    llist_entry *le;
    datum_t rootdatum;
 
