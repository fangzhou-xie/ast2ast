
/*
R package etr
Copyright (C) 2021 Konrad Krämer

This file is part of R package etr


etr is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with etr
If not see: https://www.gnu.org/licenses/old-licenses/gpl-2.0.html#SEC4
*/

#ifndef A2A_H
#define A2A_H

#include "ad_etr/add_ad.hpp"
#include "ad_etr/mul_ad.hpp"
#include "ad_etr/subtract_ad.hpp"
#include "ad_etr/mul_ad.hpp"
#include "ad_etr/exponent_ad.hpp"
#include "ad_etr/pointer_storage.hpp"
#include "ad_etr/vec_ad.hpp"
#include "etr_bits/header.hpp"
#include "etr_bits/util.hpp"

#include "etr_bits/concatenate.hpp"
// #include "etr_bits/colon.hpp"
#include "etr_bits/allocation.hpp"
#include "etr_bits/print.hpp"

#define sexp etr::VEC<double>

#endif
