#include <Arduino.h>

#include "datatypes.h"
#include "proc.h"
#include "ui.h"
#include "_api.h"

#include "common/datatypes.h"

template class dataTypes::List<String>;
template class dataTypes::List<proc::Process>;
template class dataTypes::List<ui::Screen>;
template class dataTypes::List<api::StoredInstance>;