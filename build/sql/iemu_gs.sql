DROP TABLE IF EXISTS `character_style`;
CREATE TABLE `character_style` (
  `character_id` int(8) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `characters`;
CREATE TABLE `characters` (
  `id` int(8) NOT NULL AUTO_INCREMENT,
  `account_id` int(8) NOT NULL,
  `charname` varchar(16) NOT NULL,
  `class` int(1) NOT NULL,
  `level` int(3) NOT NULL DEFAULT '1',
  `sex` int(1) NOT NULL,
  `access` enum('PLAYER','GAMEMASTER','ADMINISTRATOR') DEFAULT 'PLAYER',
  `pos_x` double DEFAULT NULL,
  `pos_y` double DEFAULT NULL,
  `pos_z` double DEFAULT NULL,
  `rotate` double DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2424832 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `npc`;
CREATE TABLE `npc` (
  `id` int(8) NOT NULL,
  `zone` int(4) DEFAULT NULL,
  `x` float DEFAULT NULL,
  `y` float DEFAULT NULL,
  `z` float DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `pin_codes`;
CREATE TABLE `pin_codes` (
  `account_id` int(8) DEFAULT NULL,
  `code` varchar(5) DEFAULT NULL,
  `errors` int(1) NOT NULL DEFAULT '0',
  `date` int(8) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;