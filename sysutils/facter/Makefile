# New ports collection makefile for:	facter
# Date created:		2007-03-03
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD: ports/sysutils/facter/Makefile,v 1.6 2009/06/23 12:03:02 rafan Exp $
#

PORTNAME=	facter
PORTVERSION=	1.5.6
CATEGORIES=	sysutils ruby
MASTER_SITES=	http://www.reductivelabs.com/downloads/facter/

MAINTAINER=	cherry@trombik.org
COMMENT=	A cross-platform Ruby library for retrieving facts from OS

NO_BUILD=	yes

USE_RUBY=	yes

.include <bsd.port.pre.mk>

do-install:
	cd ${WRKSRC} && \
	${SETENV} PREFIX=${PREFIX} ${RUBY} ${WRKSRC}/install.rb

.include <bsd.port.post.mk>
