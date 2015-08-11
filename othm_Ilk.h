#ifndef OTHM_ILK_H
#define OTHM_ILK_H

struct Ilk_plugin {
	struct othm_funct *reconstruct;
	char *type_name;
};

struct Ilk_reader {
	struct othm_hashmap *data;
	struct othm_hashmap *plugins;
	struct othm_funct *read;
};

struct Ilk_prog_state {
	struct Ilk_reader;
};

#define OTHM_ILK_PLUGIN_INIT(ILK_FUNCT, NAME, TYPE_NAME, RETURN_TYPE)	\
	RETURN_TYPE ILK_FUNCT ();					\
	struct othm_funct OTHM_ILK_PLUGIN_OTHM_FUNCT ## ILK_FUNCT = {	\
		.function = (void (*) (void)) ILK_FUNCT,		\
		.name = #NAME						\
        };								\
	struct Ilk_plugin OTHM_ILK_PLUGIN ## ILK_FUNCT = {		\
		.reconstruct = &OTHM_ILK_PLUGIN_OTHM_FUNCT ## ILK_FUNCT, \
		.type_name = #TYPE_NAME					\
	}

#endif
