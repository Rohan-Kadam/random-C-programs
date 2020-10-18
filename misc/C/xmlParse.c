#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#ifdef LIBXML_TREE_ENABLED

static void
print_tree(xmlDoc *doc, xmlNode *root_node)
{
    xmlNode *cur_node = NULL;
    xmlChar *key;

    for (cur_node = root_node; cur_node; cur_node = cur_node->next)
    {
        if (cur_node->type == XML_ELEMENT_NODE)
        {
            printf("<%s>\n", cur_node->name);
            key = xmlNodeListGetString(doc, cur_node->xmlChildrenNode, 1);
            printf("keyword: %s\n", key);
            xmlFree(key);
        }

        print_tree(doc, cur_node->children);
    }
}


int main(int argc, char **argv)
{
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    if (argc != 2)
        return(1);


    doc = xmlReadFile(argv[1], NULL, 0);
    //doc = xmlParseDoc("<xyz>2</xyz>");	//parse an XML in-memory document and build a tree INSTEAD OF a file


    if (doc == NULL )
    {
        printf("Document parsing failed!!! \n");
        exit (1);
    }
    
    root_element = xmlDocGetRootElement(doc);
    
    if (root_element == NULL)
    {
        printf("Document is empty\n");
        xmlFreeDoc(doc);
        exit(1);
    }

    print_tree(doc, root_element);

    xmlFreeDoc(doc);

    xmlCleanupParser();

    return 0;
}
#else
int main(void)
{
    printf("Tree support not compiled in\n");
    exit(1);
}
#endif
