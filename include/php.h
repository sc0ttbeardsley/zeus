/*
 * Copyright (c) 2015, Yahoo Inc. All rights reserved.
 * Copyrights licensed under the New BSD License.
 * See the accompanying LICENSE file for terms.
 */

#ifndef PHP_H
#define PHP_H

#include "generator.h"
#include "ir.h"

struct PHPGenerator : public Generator {
  void header(Printer &, const ir::Namespaces &);

  void structure(Printer &, const ir::Structure &);

  void dimension(Printer &, const ir::DimensionEnumeration &);

  void key(Printer &, const ir::Key &);
  void keyDimension(Printer &, const ir::Key &,
      const ir::Dimension &, const int);

  void configurationClass(Printer &, const ir::Snapshot &);

  void generate(Printer &, const ir::Snapshot &);

  void content(Printer &, const Type::TYPES,
      const std::string &);

  void value(Printer &, const Value &,
      const std::string &, const int);

  bool nativeType(const std::string & s) const {
    return s == "boolean"
      || s == "float"
      || s == "integer"
      || s == "string";
  }
};

#endif
