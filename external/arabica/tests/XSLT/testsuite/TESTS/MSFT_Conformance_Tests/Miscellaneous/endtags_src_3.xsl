<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:output method="xml" omit-xml-declaration="yes" />
<xsl:template match="/">
	<xsl:for-each select="//EMPTY"><xsl:copy></xsl:copy></xsl:for-each>
</xsl:template>
</xsl:stylesheet>