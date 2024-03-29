# xml-encode-by-C
Encode XML special  characters by using simple C code

|special characters|entities|
|---|---
|&|`&amp;`
|'|`&apos;`
|"|`&quot;`
|<|`&lt;`
|>|`&gt;`

[WiKi reference](https://en.wikipedia.org/wiki/XML#Escaping)


#### 1. download repository 
    git clone https://github.com/melody26613/xml-encode-by-C.git


#### 2. change path to xml-encode-by-C
    cd xml-encode-by-C/


#### 3. build code
    make clean; make


#### 4. use xml_encode, example:

    ./sample "&'\"<>"

    result

    input str: &'"<>

    encode:    &amp;&apos;&quot;&lt;&gt;

    decode:    &'"<>



    ./sample "&&&''\"<>>><"

    result

    input str: &&&''"<>>><

    encode:    &amp;&amp;&amp;&apos;&apos;&quot;&lt;&gt;&gt;&gt;&lt;

    decode:    &&&''"<>>><



    ./sample "&amp;&amp;&\"<&apos;>>><"

    result: 

    input str: &amp;&amp;&"<&apos;>>><

    encode: &amp;amp;&amp;amp;&amp;&quot;&lt;&amp;apos;&gt;&gt;&gt;&lt;

    decode: &amp;&amp;&"<&apos;>>><


#### 5. unit test by googletest

please reference code under test/ and [test/README.md](https://github.com/melody26613/xml-encode-by-C/blob/master/test/README.md)
