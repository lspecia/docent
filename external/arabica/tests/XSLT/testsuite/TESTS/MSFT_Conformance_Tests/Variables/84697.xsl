<xsl:stylesheet version='1.0' xmlns:xsl='http://www.w3.org/1999/XSL/Transform'>  

<!-- BUG# 49422 XSLT: Refering to undeclared Arabic/Hebrew spelled variable returns error msg with var name displayed as ?'s -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/05/2000 -->

<xsl:variable name="ضصثقفغ">
	<xsl:value-of select="$ضصثقفغ"/>
</xsl:variable>

</xsl:stylesheet>  
