DROP TABLE IF EXISTS `accounts`;
CREATE TABLE `accounts` (
  `id` int(8) NOT NULL AUTO_INCREMENT,
  `login` varchar(32) NOT NULL,
  `password` varchar(128) NOT NULL COMMENT 'md5',
  `email` varchar(128) NOT NULL,
  `email_status` int(1) DEFAULT '0',
  `access` int(1) DEFAULT '0',
  `hash` varchar(64) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=0 DEFAULT CHARSET=utf8;
