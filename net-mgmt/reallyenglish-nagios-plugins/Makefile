# New ports collection makefile for:	reallyenglish-nagios-plugins
# Date created:		2010-06-30
# Whom:			Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
#
# $FreeBSD$
#

PORTNAME=	reallyenglish-nagios-plugins
PORTVERSION=	0.6
#PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	http://journal.reallyenglish.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Nagios plugins at reallyenglish

RUN_DEPENDS+=	${LOCALBASE}/libexec/nagios/utils.sh:${PORTSDIR}/net-mgmt/nagios-plugins \
	${SITE_PERL}/Nagios/Plugin.pm:${PORTSDIR}/net-mgmt/p5-Nagios-Plugin \
	${LOCALBASE}/sbin/megarc:${PORTSDIR}/sysutils/megarc \
	${LOCALBASE}/sbin/amrstat:${PORTSDIR}/sysutils/amrstat

NO_BUILD=	Yes
MAKE_ARGS=	DESTDIR=${PREFIX}

.include <bsd.port.pre.mk>

# XXX this should be fixed in the upstream
pre-install:
	${INSTALL} -d ${PREFIX}/libexec/nagios

.include <bsd.port.post.mk>
