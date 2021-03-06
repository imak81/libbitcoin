/*
 * Copyright (c) 2011-2013 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_ERROR_HPP
#define LIBBITCOIN_ERROR_HPP

#include <string>
#include <system_error>
#include <bitcoin/bitcoin/define.hpp>

namespace libbitcoin {

namespace error
{
    // Specific errors
    enum error_code_t
    {
        service_stopped = 1,
        operation_failed,
        // blockchain errors
        not_found,
        duplicate,
        unspent_output,
        unsupported_payment_type,
        // network errors
        resolve_failed,
        network_unreachable,
        address_in_use,
        listen_failed,
        accept_failed,
        bad_stream,
        channel_timeout,
        // transaction pool
        blockchain_reorganized,
        pool_filled,
        // validate tx
        coinbase_transaction,
        is_not_standard,
        double_spend,
        input_not_found,
        // check_transaction()
        empty_transaction,
        output_value_overflow,
        invalid_coinbase_script_size,
        previous_output_null,
        // validate block
        previous_block_invalid,
        // check_block()
        size_limits,
        proof_of_work,
        futuristic_timestamp,
        first_not_coinbase,
        extra_coinbases,
        too_many_sigs,
        merkle_mismatch,
        // accept_block()
        incorrect_proof_of_work,
        timestamp_too_early,
        non_final_transaction,
        checkpoints_failed,
        old_version_block,
        coinbase_height_mismatch,
        // connect_block()
        duplicate_or_spent,
        validate_inputs_failed,
        fees_out_of_range,
        coinbase_too_large
    };

    enum error_condition_t
    {
        // validate
        validate_failed = 1,
        forced_removal
    };

    BC_API std::error_code make_error_code(error_code_t e);
    BC_API std::error_condition make_error_condition(error_condition_t e);
}

class error_category_impl
  : public std::error_category
{
public:
    BC_API virtual const char* name() const noexcept;
    BC_API virtual std::string message(int ev) const noexcept;
    BC_API virtual std::error_condition
        default_error_condition(int ev) const noexcept;
};

const std::error_category& error_category();

} // namespace libbitcoin

namespace std
{
    template <>
    struct BC_API is_error_code_enum<
        libbitcoin::error::error_code_t>
      : public true_type {};

    template <>
    struct BC_API is_error_condition_enum<
        libbitcoin::error::error_condition_t>
      : public true_type {};
}

#endif

