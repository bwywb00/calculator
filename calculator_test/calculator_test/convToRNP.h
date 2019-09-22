#pragma once

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "ArrStack.h"
#include "util.h"

void convToRNP(char exp[]);
char ** convToRNP_P(char exp[]);