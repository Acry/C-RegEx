

#Regular expressions (RegEx) in C


RegEx aren't part of Standard C. There are 2 major FOSS-implementations:

The POSIX RegEx library and Perl Compatible RegEx PCRE.

The [POSIX syntax](https://www.regular-expressions.info/posix.html) is the syntax used by `grep`, `sed`, `vi`, [etc](https://www.regular-expressions.info/gnu.html).

Perl syntax is what most programming languages, like Java, JavaScript, Python, lean on. 

##POSIX RegEx

POSIX.2 RegEx

RegEx as defined in POSIX.2, come in two forms:
 
modern  RegEx (roughly those of egrep; POSIX.2 calls these "extended" RegEx)
and 
obsolete RegEx (roughly those of ed(1); POSIX.2 "basic" REsRegEx

### More Info
`man 3 regex`, `man 7 regex`

##PCRE

New projects are advised to use the new PCRE2 libraries.

>PCRE2 is a revised API for the library, and is incompatible with the original PCRE API.

If you have a proper installation of pcre2, you should have the API-Help as HTML `/usr/share/doc/pcre2/html/index.htm` or similar.

There is a sample file included, if you don't have it, because your distro is not developer friendly: <https://github.com/luvit/pcre2/blob/master/src/pcre2demo.c>, there you go. For convenience I include the file in the Build-File; see: `man pcre2sample`

For didactical reasons, the counterpart to `posix_re` is `pcre2`.


### More Info

`man 3 pcre`

<http://www.pcre.org/>

<https://www.regular-expressions.info/pcre.html>
<https://www.regular-expressions.info/pcre2.html>


##Further Links

###Selection of some online RegEx-Tester

<http://www.rexv.org/>
<https://regex101.com/>

###Regular Expression Library

http://regexlib.com/

###More Background

http://en.wikipedia.org/wiki/Regular_expression

###A few reviews of books on RegEx

https://www.regular-expressions.info/books.html

###Learning Sites

https://www.regular-expressions.info/
https://www.rexegg.com/
https://regexone.com/
