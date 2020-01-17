// { dg-options "-std=gnu++17" }
// { dg-do run { target c++17 } }

// Copyright (C) 2017-2020 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// C++17 30.10.7.4.7 path generic format observers [fs.path.generic.obs]

#include <filesystem>
#include <testsuite_hooks.h>

using std::filesystem::path;

void
test01()
{
  VERIFY( path().generic_string() == "" );
  VERIFY( path("/").generic_string() == "/" );
  VERIFY( path("////").generic_string() == "/" );
#ifdef __CYGWIN__
  VERIFY( path("//a").generic_string() == "//a" );
  VERIFY( path("//a/").generic_string() == "//a/" );
  VERIFY( path("//a/b").generic_string() == "//a/b" );
#else
  VERIFY( path("//a").generic_string() == "/a" );
  VERIFY( path("//a/").generic_string() == "/a/" );
  VERIFY( path("//a/b").generic_string() == "/a/b" );
#endif
  VERIFY( path("/a//b").generic_string() == "/a/b" );
  VERIFY( path("/a//b/").generic_string() == "/a/b/" );
  VERIFY( path("/a//b//").generic_string() == "/a/b/" );
  VERIFY( path("/a//b//.").generic_string() == "/a/b/." );
}

void
test02()
{
  // PR libstdc++/93244
  path p("C:");
  p += path::preferred_separator;
  p += "foo/bar";
  VERIFY( p.generic_string() == "C:/foo/bar" );
}

int
main()
{
  test01();
  test02();
}
