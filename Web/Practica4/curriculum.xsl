<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format" >
		<xsl:template match="curriculum">
		<html>
			<head>
				<title>Curriculum Vitae</title>
    			<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    			<link href="Estilos/style.css" rel="stylesheet" type="text/css" />
			</head>
			<body style="font-family: Arial; background-color: #C0C0C0;">
				<h1>Curriculum</h1>				
				<xsl:variable name="archivo-imagen"><xsl:value-of select="@imagen"/></xsl:variable>
				<img style="width: 10%; float: right;" src="Img/{$archivo-imagen}" alt="ImagenBio"></img>
				<xsl:for-each select="seccion">
					<strong><xsl:value-of select="@nombre"/></strong>
					<br/>
					<xsl:for-each select="valor">
						<li><xsl:value-of select="contenido"/></li>
					</xsl:for-each>
				</xsl:for-each>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>