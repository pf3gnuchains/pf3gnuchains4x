/* gdbserv-utils.h

   Copyright 1998, 2000, 2002 Red Hat, Inc.

   This file is part of RDA, the Red Hat Debug Agent (and library).

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
   
   Alternative licenses for RDA may be arranged by contacting Red Hat,
   Inc.  */

#ifdef __cplusplus
extern "C" {
#elif 0
}
#endif

struct gdbserv;
struct gdbserv_reg;

/* Return the ASCII equivalent of C (C>=0 && C<=15). The result will be 
   lower-case. */

extern unsigned char gdbserv_to_hex (int c);
extern int gdbserv_hex_to (unsigned char c);

extern unsigned int gdbserv_ulong_to_hex (char *ptr, unsigned long val, int num_bits);


extern unsigned int gdbserv_raw_to_hex (char **ptr, char *mem, int nr_bytes);

/* Convert between a REG and the native unsigned long/long-long. */

extern void gdbserv_reg_to_ulong (struct gdbserv *gdbserv,
				  const struct gdbserv_reg *reg,
				  unsigned long *val);

extern void gdbserv_reg_to_ulonglong (struct gdbserv *gdbserv,
				      const struct gdbserv_reg *reg,
				      unsigned long long *val);

extern void gdbserv_ulong_to_reg (struct gdbserv *gdbserv,
				  unsigned long val,
				  struct gdbserv_reg *reg);

extern void gdbserv_ulonglong_to_reg (struct gdbserv *gdbserv,
				      unsigned long long val,
				      struct gdbserv_reg *reg);

/* Convert between a REG and a buffer representing a (possibly signed)
   numeric type.  Handle big endian and little endian cases explicitly.
   When the source buffer is bigger than the destination buffer, the
   least significant bytes (as appropriate for the endianess) are
   transferred.  When the source buffer is smaller than the destination,
   the most significant bytes of the destination are padded appropriately.
   
   Note that gdbserv_be_bytes_from_reg() and gdbserv_le_bytes_from_reg()
   have a buffer length parameter, but not a register length
   parameter.  This is because the register length was obtained from a
   register packet sent by the debug client.  On the other hand,
   gdbserv_be_bytes_to_reg() and gdbserv_le_bytes_to_reg() take both a
   buffer length and the register length.  This is because we're
   constructing a register (which will likely be sent to the client)
   of a particular size.  */

extern void gdbserv_be_bytes_to_reg (struct gdbserv *gdbserv,
		                     const void *buf,
		                     int buflen,
		                     struct gdbserv_reg *reg,
				     int reglen,
				     int sign_extend);

extern void gdbserv_le_bytes_to_reg (struct gdbserv *gdbserv,
		                     const void *buf,
		                     int len,
		                     struct gdbserv_reg *reg,
				     int reglen,
				     int sign_extend);

extern void gdbserv_be_bytes_from_reg (struct gdbserv *gdbserv,
		                       void *buf,
		                       int buflen,
                                       const struct gdbserv_reg *reg,
				       int sign_extend);

extern void gdbserv_le_bytes_from_reg (struct gdbserv *gdbserv,
		                       void *buf,
		                       int buflen,
                                       const struct gdbserv_reg *reg,
				       int sign_extend);

/* Convert between a REG and a buffer representing a native unsigned
   numeric type.  These are just wrappers for the routines above, but
   are useful nonetheless since they free the caller from having to
   worry about byte order issues.  */

extern void gdbserv_host_bytes_to_reg (struct gdbserv *gdbserv,
		                       const void *buf,
		                       int buflen,
		                       struct gdbserv_reg *reg,
				       int reglen,
				       int sign_extend);

extern void gdbserv_host_bytes_from_reg (struct gdbserv *gdbserv,
		                         void *buf,
		                         int buflen,
                                         const struct gdbserv_reg *reg,
					 int sign_extend);

#ifdef __cplusplus
}
#endif
